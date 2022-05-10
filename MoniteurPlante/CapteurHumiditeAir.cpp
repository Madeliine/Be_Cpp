#include "CapteurHumiditeAir.h"

///////////Constructeur//////////// 
CapteurHumiditeAir::CapteurHumiditeAir(int p, uint8_t type) : CapteurDHT(p, type){}

/////////////Méthodes//////////////
float CapteurHumiditeAir::Read(){
  value = capt.readHumidity();
  if (isnan(value)) {
    Serial.println(F("Failed to read humidity from DHT sensor!"));
    value = -1;
  }
  return value;
}

void CapteurHumiditeAir::AfficherValeur(){
  Serial.print("Humidité air: ");
  Serial.print(value);
  Serial.println("%");
}
