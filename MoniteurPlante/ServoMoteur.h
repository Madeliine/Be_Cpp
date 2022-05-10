#ifndef SERVOMOTEUR_FILE_H
#define SERVOMOTEUR_FILE_H

#include "Arduino.h"
#include "Actionneur.h"
#include <Servo.h>

#define DELTA_ANGLE 20

class ServoMoteur : public Actionneur{
  private :
    bool sensHoraire;
  protected:
    Servo monServo;
  public:

    //Constructeur 
    ServoMoteur(int p);

    //Méthodes
    void ChangeAngle(int angle);
    void Activate() override;
};
#endif;
