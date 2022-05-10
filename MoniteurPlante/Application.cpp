#include "Application.h"

///////////Constructeur//////////// 
Application::Application () {
  aArrose = false;
  aHumidifie = false;
  tempsDepuisDernierArrosage = 2147483647; //variable initialisée au plus grand "int" 
  tempsDepuisDerniereBrume = 2147483647; //Pareil
  tempsDepuisDerniereRotation = 0;

}

/////////////Méthodes//////////////
void Application::Initialisation () {
  
  Serial.begin(115200);
  delay(1000);

  /////////////////Initialisation des actionneurs ///////////////////////////

  //mesActionneurs[0]
  pinMode (PIN_POMPE_A_EAU, OUTPUT);
  PompeAEau * act1 = new PompeAEau (PIN_POMPE_A_EAU);
  mesActionneurs.push_back(act1);
  
  //mesActionneurs[1]
  pinMode (PIN_BRUME, OUTPUT);
  Brumisateur * act2 = new Brumisateur (PIN_BRUME);
  mesActionneurs.push_back(act2);

  //mesActionneurs[2]
  pinMode (PIN_SERVO_PLATEFORME, OUTPUT);
  ServoMoteur * act3 = new ServoMoteur (PIN_SERVO_PLATEFORME);
  mesActionneurs.push_back(act3);

  //mesActionneurs[3]
  pinMode (PIN_LEDS, OUTPUT);
  Leds * act4 = new Leds (PIN_LEDS);
  mesActionneurs.push_back(act4);
  
  /////////////////Initialisation des capteurs ///////////////////////////

  //mesCapteurs[0]
  CapteurHumiditeSol* capt1 = new CapteurHumiditeSol (PIN_CAPTEUR_HUMIDITE_SOL);
  mesCapteurs.push_back(capt1);
  
  //mesCapteurs[1]
  pinMode (PIN_CAPTEUR_HUMIDITE_AIR_TEMP, INPUT);
  CapteurHumiditeAir* capt2 = new CapteurHumiditeAir (PIN_CAPTEUR_HUMIDITE_AIR_TEMP, DHTTYPE);
  mesCapteurs.push_back(capt2);
  
  //mesCapteurs[2]
  pinMode (PIN_CAPTEUR_HUMIDITE_AIR_TEMP, INPUT);
  CapteurTemp* capt3 = new CapteurTemp (PIN_CAPTEUR_HUMIDITE_AIR_TEMP, DHTTYPE);
  mesCapteurs.push_back(capt3);

  // mesCapteurs[3]
  CapteurLuminosite* capt4 = new CapteurLuminosite (PIN_CAPTEUR_LUMINOSITE);
  mesCapteurs.push_back(capt4);

  /////////////////Initialisation de l'ADC ///////////////////////////
  
  adc.Initi();

  Serial.println ("Tout a été initilisé");
  delay(1000);
}

/* Le test de la plateforme consiste à l'activer (donc la faire tourner 
d'un certain angle) après au moins un certain temps d'attente */
void Application::TestPlateforme() {
  Serial.println("Test Plateforme");
  if ((millis() - tempsDepuisDerniereRotation) > TEMPS_ATTENTE_TOURNE_PLATEFORME) {
    tempsDepuisDerniereRotation = millis();
    (*mesActionneurs[2]).Activate();
    Serial.println("Plateforme activée");
  }
  else{
    // Il se passe rien
    Serial.println("Plateforme désactivée");
  }
  Serial.println();
}

/* Le test de l'arrosage consiste à déclencher la pompe à eau suivant un cycle d'hystérésis. 
On attend de mesurer un certain niveau d'humidité bas pour activer une première fois la pompe, puis 
elle est activée régulièrement jusqu'à obtenir un niveau d'humidité haut */

void Application::TestArrosage() {
  Serial.println("Test Arrosage");
  if (((*mesCapteurs[0]).Read(&adc) < LIMITE_HUMIDITE_TERRE_BASSE) and ((millis() - tempsDepuisDernierArrosage) > TEMPS_ATTENTE_AVANT_ARROSAGE) )
  {
    aArrose = true;
    (*mesActionneurs[0]).Activate();
    tempsDepuisDernierArrosage = millis();
  }
  else if (( aArrose == true) and ((*mesCapteurs[0]).Read(&adc) < LIMITE_HUMIDITE_TERRE_HAUTE) and ((millis() - tempsDepuisDernierArrosage) > TEMPS_ATTENTE_AVANT_ARROSAGE)){
    aArrose = true;
    (*mesActionneurs[0]).Activate();
    tempsDepuisDernierArrosage = millis();
  }
  else if ((*mesCapteurs[0]).Read(&adc) > LIMITE_HUMIDITE_TERRE_HAUTE){
    aArrose = false;
  }
  (*mesCapteurs[0]).AfficherValeur();
  Serial.println();
  
}

/* Le test de la brume consiste à activer le brumisateur suivant un cycle d'hystérésis.
On attend de mesurer un certain niveau d'humidité bas de l'air (modulé par la valeur de la température) pour activer la brume. Celle-ci sera désactivée 
quand le taux d'humidité dans l'air sera à un certain niveau d'humidité haut d'air (également modulé par la valeur de la température).
L'intérêt de moduler notre seuil par la valeur de la température est qu'une plante à 10 degrés a besoin de moins d'humidité dans l'air
qu'une plante à 30 degrés */
void Application::TestBrume() { 
  Serial.println("Test Brume");
  if (((*mesCapteurs[1]).Read() < (LIMITE_HUMIDITE_AIR_BASSE + (*mesCapteurs[2]).Read()-20)) and (aHumidifie == false))
  {
    (*mesActionneurs[1]).Activate();
    aHumidifie = true;
  }
  else if ((aHumidifie == true) and ((*mesCapteurs[1]).Read() > LIMITE_HUMIDITE_AIR_HAUTE + (*mesCapteurs[2]).Read()-20))
  {
    aHumidifie = false;
    (*mesActionneurs[1]).Desactivate();
    tempsDepuisDerniereBrume = millis();
  }
  (*mesCapteurs[1]).AfficherValeur();
  (*mesCapteurs[2]).AfficherValeur();
  Serial.println();
}


/* Le test de la lumière consiste à allumer la LED que si la lumière ambiante est en dessous d'un certain seuil. 
 Cela signifie que celle-ci n'est pas suffisante pour subvenir aux besoins de la plante. 
 La fonctionnalité de s'éteindre la nuit n'a pas été développée car il faudrait pouvoir récupérer l'heure réelle. */
void Application::TestLeds() {
  if ((*mesCapteurs[3]).Read(&adc) < SEUIL_LUMIERE) {
    (*mesActionneurs[3]).Activate();
  }
  else {
    (*mesActionneurs[3]).Desactivate();
  }
  (*mesCapteurs[3]).AfficherValeur();
  Serial.println();
}

/* Cette fonction est appelée par MoniteurPlante.io*/
void Application::Launch() {
 TestPlateforme();
 TestBrume();
 TestArrosage();
 TestLeds();
 delay(2000);

}
