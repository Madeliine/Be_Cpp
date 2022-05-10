#include <DHT.h>

#ifndef APPLICATION_FILE_H
#define APPLICATION_FILE_H

#include "CapteurHumiditeSol.h"
#include "PompeAEau.h"
#include "Brumisateur.h"
#include "ServoMoteur.h"
#include "Leds.h"
#include "CapteurHumiditeAir.h"
#include "CapteurTemp.h"
#include "CapteurDHT.h"
#include "CapteurLuminosite.h"
#include "ADC.h"
#include "Arduino.h"

//Utilisation de la STL <vector> pour faciliter la gestion des composants de l'application
#include <vector>

using namespace std;

////////////////////// Définition des pins ////////////////////////////////
#define PIN_CAPTEUR_HUMIDITE_SOL 0
#define PIN_CAPTEUR_HUMIDITE_AIR_TEMP D3
#define DHTTYPE DHT11
#define PIN_CAPTEUR_LUMINOSITE 1
#define PIN_POMPE_A_EAU D7
#define PIN_BRUME D6
#define PIN_SERVO_PLATEFORME D5
#define PIN_LEDS LED_BUILTIN

////////////////////// Définition des seuils //////////////////////////////
#define LIMITE_HUMIDITE_TERRE_HAUTE 80
#define LIMITE_HUMIDITE_TERRE_BASSE 40
#define TEMPS_ATTENTE_AVANT_ARROSAGE 3000
#define LIMITE_HUMIDITE_AIR_HAUTE 70
#define LIMITE_HUMIDITE_AIR_BASSE 60
#define SEUIL_LUMIERE 20

//////// Définition des délais d'attente (en milisecondes)/////////////////
#define TEMPS_ATTENTE_AVANT_BRUME 30000
#define TEMPS_ATTENTE_TOURNE_PLATEFORME 10000
#define TEMPS_ATTENTE_ALLUME 3600000



class Application {
  vector<Capteur *> mesCapteurs;
  vector <Actionneur *> mesActionneurs;
  bool aArrose;
  bool aHumidifie ;
 
  int tempsDepuisDernierArrosage;
  int tempsDepuisDerniereRotation;
  int tempsDepuisDerniereBrume;
  
  ADC adc;
  
  public :

  //Constructeur 
  Application();

  //Méthodes
  void Initialisation();
  void Launch ();
  void TestPlateforme();
  void TestBrume();
  void TestArrosage();
  void TestLeds();
};

#endif //APPLICATION_FILE_H
