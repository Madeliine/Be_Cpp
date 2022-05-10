#ifndef POMPEAEAU_FILE_H
#define POMPEAEAU_FILE_H

#include "Arduino.h"
#include "Actionneur.h"

class PompeAEau : public Actionneur {
  public:
    //Constructeur 
    PompeAEau(int p);

    //Méthodes
    void Activate() override;
};

#endif
