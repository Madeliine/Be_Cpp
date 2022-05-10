#ifndef CAPTEURHUMIDITEAIR_FILE_H
#define CAPTEURHUMIDITEAIR_FILE_H

#include "Arduino.h"
#include "CapteurDHT.h"
#include "DHT.h"

class CapteurHumiditeAir : public CapteurDHT {

public :

//Constructeur 
CapteurHumiditeAir(int p, uint8_t type);

//Méthodes
float Read() override;
void AfficherValeur() override;
};


#endif 
