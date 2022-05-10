
#include "Actionneur.h"

///////////Constructeur//////////// 
Actionneur::Actionneur(int p) : Composant(p) {}

/////////////Méthodes//////////////
void Actionneur::Desactivate(){
  digitalWrite(GetPin(),LOW);
  }
