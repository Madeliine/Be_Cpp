#include "Composant.h"

///////////Constructeur//////////// 
Composant::Composant(int p) : pin (p){}


/////////////Méthodes//////////////
int Composant::GetPin(){
  return this->pin;
}
