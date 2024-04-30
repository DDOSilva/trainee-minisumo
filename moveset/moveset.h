#ifndef MAIN_H
#define MAIN_H

#include "motor.h"
#include "vision.h"

class Moveset{
    public:
        Motor rightMotor;
        Motor leftMotor;
        Vision vision; // precisava declarar aqui?

        void update();
        Strat(Motor rightMotor, Motor leftMotor, Vision vision); // devia usar ponteiros?

};

#endif