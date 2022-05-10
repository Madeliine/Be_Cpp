#ifndef CAPTEUR_FILE_H
#define CAPTEUR_FILE_H

#include "Composant.h"
#include "Arduino.h"
#include "ADC.h"

class Capteur : public Composant {
  protected:
  float value;
  public : 
  //Constructeur 
  Capteur (int p);

  //Méthodes
  float virtual Read (); //Fonction actuellement non utilisée mais permet d'adapter le programme si pas besoin d'ADC
  float virtual Read (ADC* adc);
  void virtual AfficherValeur() = 0;
};


#endif //CAPTEUR_FILE_H
