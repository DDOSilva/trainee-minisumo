#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "vision.h"
#include "digital_sensor.h"
#include "microstart.h"

#define

class Moveset{
    public:
        Moveset();
        Motor rightMotor;
        Motor leftMotor;
        Vision vision; 
        Microstarter uStart;
        DigitalSensor fSensor;
        DigitalSensor rSensor;
        DigitalSensor full_rSensor;
        DigitalSensor lSensor;
        DigitalSensor full_lSensor;


        void update(Motor &rightMotor, Motor &leftMotor, Vision &vision, Microstarter &uStart, DigitalSensor &fSensor
        DigitalSensor &rSensor, DigitalSensor &full_rSensor, DigitalSensor &lSensor, DigitalSensor &full_lSensor);
        
};

#endif