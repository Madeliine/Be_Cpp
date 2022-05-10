#ifndef CAPTEURDHT_FILE_H
#define CAPTEURDHT_FILE_H

#include "Arduino.h"
#include "Capteur.h"
#include "DHT.h"

class CapteurDHT : public Capteur {
  protected:
  static DHT capt;

  public: 
  //Méthodes
  static bool existe;
  
  //Constructeur 
  CapteurDHT(int p, uint8_t type);
  
};

#endif
