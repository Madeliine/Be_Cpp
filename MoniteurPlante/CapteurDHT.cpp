#include "CapteurDHT.h"

  /////////////Méthodes//////////////
  bool CapteurDHT::existe = false;
  DHT CapteurDHT::capt = DHT(0, DHT11, 6);

  ///////////Constructeur//////////// 
  CapteurDHT::CapteurDHT(int p, uint8_t type): Capteur::Capteur(p){
      Serial.println ("capteurDHT construit");

    if (existe == false){
      existe = true;
      capt = DHT(uint8_t(p), type, 6);
      capt.begin();
    }
  }
