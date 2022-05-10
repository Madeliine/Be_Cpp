#ifndef ACTIONNEUR_FILE_H
#define ACTIONNEUR_FILE_H

#include "Composant.h"
#include "Arduino.h"

class Actionneur : public Composant {
  public : 
  
  //Méthodes
  void virtual Activate () = 0;
  void virtual Desactivate();

  //Constructeur 
  Actionneur(int p);
};


#endif //ACTIONNEUR_FILE_H
