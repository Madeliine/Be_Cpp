#include "CapteurTemp.h"

///////////Constructeur//////////// 
CapteurTemp::CapteurTemp(int p, uint8_t type) : CapteurDHT(p, type){}


/////////////Méthodes//////////////
float CapteurTemp::Read(){
  value = capt.readTemperature();
  if (isnan(value)) {
    Serial.println("Failed to read température from DHT sensor!");
    value = -1;
  }
  return value;
}

void CapteurTemp::AfficherValeur(){
  Serial.print("Température : ");
  Serial.print(value);
  Serial.println("°C");
}
