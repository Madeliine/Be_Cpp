#ifndef CAPTEMP_FILE_H
#define CAPTEMP_FILE_H

#include "Arduino.h"
#include "CapteurDHT.h"
#include "DHT.h"

class CapteurTemp : public CapteurDHT {
public :

  //Constructeur 
  CapteurTemp(int p,uint8_t type);

  //Méthodes
  float Read() override;
  void AfficherValeur() override;
};


#endif 
