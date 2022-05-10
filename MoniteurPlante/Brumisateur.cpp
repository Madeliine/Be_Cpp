#include "Brumisateur.h"

///////////Constructeur//////////// 
Brumisateur::Brumisateur(int p):Actionneur(p){
   digitalWrite(p,LOW);
  };

/////////////Méthodes//////////////
void Brumisateur::Activate(){
  digitalWrite(GetPin(),HIGH);
  Serial.println("Brume On");

}
void Brumisateur::Desactivate(){
    digitalWrite(GetPin(),LOW);
    Serial.println("Brume Off");
}
