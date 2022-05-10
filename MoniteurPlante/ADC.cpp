
#include "ADC.h"

  ///////////Constructeur//////////// 
  ADC::ADC() : ads(&Wire){}

  /////////////Méthodes//////////////
  void ADC::Initi()
  {
    ads.setAddr_ADS1115(ADS1115_IIC_ADDRESS1);   // 0x49
    ads.setGain(eGAIN_TWOTHIRDS);   // 2/3x gain
    ads.setMode(eMODE_SINGLE);       // single-shot mode
    ads.setRate(eRATE_128);          // 128SPS (default)
    ads.setOSMode(eOSMODE_SINGLE);   // Set to start a single-conversion
    ads.init();
  }

  int ADC::Read(int pin){
    int valeur;
    if (ads.checkADS1115()) //Permet de tester si l'adc a bien été initialisé ou s'il est bien branché
    {
        valeur = ads.readVoltage(pin);
    }
    else
    {
        Serial.println("ADS1115 Disconnected!");
    }
    return valeur;
  }
