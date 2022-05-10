#ifndef BRUMISATEUR_FILE_H
#define BRUMISATEUR_FILE_H

#include "Arduino.h"
#include "Actionneur.h"

 class Brumisateur : public Actionneur {
  public:
   //Constructeur 
   Brumisateur(int p);

   //Méthodes
   void Activate() override;
   void Desactivate() override;
 };
 #endif
