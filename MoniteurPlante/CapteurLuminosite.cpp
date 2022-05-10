#include "CapteurLuminosite.h"

///////////Constructeur//////////// 
CapteurLuminosite::CapteurLuminosite(int p):Capteur(p){}

/////////////Méthodes//////////////
float CapteurLuminosite::Read(){
  value = analogRead(GetPin());
  value = map(value, 0, 704, 0, 100);
  return value;
}

float CapteurLuminosite::Read(ADC* adc) {
  value = adc->Read(GetPin());
  value = map(value, 65, 2500, 0, 100); 
  return value;
}

void CapteurLuminosite::AfficherValeur(){
  Serial.print("Luminosité : ");
  Serial.print(value);
  Serial.println("%");
}
