#include "CapteurHumiditeSol.h"

///////////Constructeur//////////// 
CapteurHumiditeSol::CapteurHumiditeSol(int p) : Capteur (p) {}

/////////////Méthodes//////////////
float CapteurHumiditeSol::Read() {
  value = analogRead(GetPin());
  value = map(value, 0, 900, 0, 100);
  return value;
}

float CapteurHumiditeSol::Read(ADC* adc) {
  value = adc->Read(GetPin());
  if (value > 30000){
    value = 0 - (65535 - value);
  }
  value = map(value, 0, 2900, 0, 100);
  return value;
}

void CapteurHumiditeSol::AfficherValeur(){
  Serial.print("Humidité sol: ");
  Serial.print(value);
  Serial.println("%");
}
