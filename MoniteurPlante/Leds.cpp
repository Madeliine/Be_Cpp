#include "Leds.h"

///////////Constructeur//////////// 
Leds::Leds(int p):Actionneur(p){};

/////////////Méthodes//////////////

//attention, la led de la carte est inversée
void Leds::Activate(){
  digitalWrite(GetPin(),LOW);
  Serial.println("Leds On");
}

void Leds::Desactivate(){
  digitalWrite(GetPin(),HIGH);
  Serial.println("Leds Off");
}
