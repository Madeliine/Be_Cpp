#ifndef CAPTEURHUMIDITESOL_FILE_H
#define CAPTEURHUMIDITESOL_FILE_H

#include "Arduino.h"
#include "Capteur.h"

class CapteurHumiditeSol : public Capteur {
public :

//Constructeur 
CapteurHumiditeSol(int p);

//Méthodes
float Read() override;
float Read(ADC*adc) override;
void AfficherValeur() override;

};

#endif //CAPTEURHUMIDITESOL_FILE_H
