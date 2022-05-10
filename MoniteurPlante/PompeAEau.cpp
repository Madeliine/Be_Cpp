#include "PompeAEau.h"

///////////Constructeur//////////// 
PompeAEau::PompeAEau(int p): Actionneur(p){
    digitalWrite (GetPin(), HIGH);
  }

/////////////Méthodes//////////////
void PompeAEau::Activate (){
  digitalWrite(this->GetPin(),LOW);
  Serial.println("Arrosage");
  delay (1000);
  digitalWrite(this->GetPin(),HIGH);

}
