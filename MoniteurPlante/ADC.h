#ifndef ADC_FILE_H
#define ADC_FILE_H

#include "Arduino.h"
#include <Wire.h>
#include <DFRobot_ADS1115.h>


class ADC {
  private :
  DFRobot_ADS1115 ads;
  
  public :
  //Constructeur 
  ADC();

  //Méthodes
  void Initi();
  int Read(int pin);
};

#endif //ADC_FILE_H
