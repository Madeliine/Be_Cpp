
#include "Capteur.h"

///////////Constructeur//////////// 
  Capteur::Capteur (int p) : Composant(p){}
  float Capteur::Read (){
    float output_value = analogRead(GetPin());
    return output_value;
  }

/////////////Méthodes//////////////
  float Capteur::Read (ADC* adc){
    float output_value = adc->Read(GetPin());
    return output_value;
  }
