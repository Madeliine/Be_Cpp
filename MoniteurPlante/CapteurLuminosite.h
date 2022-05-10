#ifndef CAPTEURLUMINOSITE_FILE_H
#define CAPTEURLUMINOSITE_FILE_H

#include "Arduino.h"
#include "Capteur.h"

class CapteurLuminosite : public Capteur {

public :

//Constructeur 
CapteurLuminosite(int p);

//Méthodes
float Read() override;
float Read(ADC*adc) override;
void AfficherValeur() override;
};

#endif
