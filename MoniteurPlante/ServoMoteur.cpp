#include "ServoMoteur.h"

///////////Constructeur//////////// 
ServoMoteur::ServoMoteur(int p) : Actionneur(p){
  monServo.attach(p);
  ChangeAngle(0);
}

/////////////Méthodes//////////////

void ServoMoteur::ChangeAngle(int angle){
  monServo.write(angle);
}

void ServoMoteur::Activate(){
  Serial.print("angle : ");
  Serial.println(monServo.read());
  if ((this->monServo.read()+ DELTA_ANGLE > 180) and (sensHoraire == true)){ //on change de sens
    sensHoraire = false;
  }
  else if((this->monServo.read()- DELTA_ANGLE < 0) and (sensHoraire == false)){
    sensHoraire = true;
  }
  if (sensHoraire == true){
    ChangeAngle(this->monServo.read()+DELTA_ANGLE);
  }
  else{
    ChangeAngle(this->monServo.read()-DELTA_ANGLE);
  }
}
