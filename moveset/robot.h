#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "vision.h"
#include "digital_sensor.h"
#include "microstart.h"

#define MICROSTARTER_PIN

#define RIGHT_MOTOR_PWM
#define RIGHT_MOTOR_PIN1
#define RIGHT_MOTOR_PIN2
#define RIGHT_MOTOR_CHANNEL

#define LEFT_MOTOR_PWM
#define LEFT_MOTOR_PIN1
#define LEFT_MOTOR_PIN2
#define LEFT_MOTOR_CHANNEL

#define FRONT_SENSOR_PIN
#define LEFT_SENSOR_PIN
#define FULL_LEFT_SENSOR_PIN
#define RIGHT_SENSOR_PIN
#define FULL_RIGHT_SENSOR_PIN



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