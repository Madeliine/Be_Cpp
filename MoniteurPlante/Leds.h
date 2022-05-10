#ifndef LEDS_FILE_H
#define LEDS_FILE_H

#include "Arduino.h"
#include "Actionneur.h"

 class Leds : public Actionneur {
  public:

  //Constructeur 
   Leds(int p);

   //Méthodes
   void Activate() override;
   void Desactivate() override;

 };
 #endif
