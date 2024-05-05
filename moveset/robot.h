#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "vision.h"
#include "digital_sensor.h"
#include "microstart.h"

#define MICROSTARTER_PIN 24
#define STDBY 26

#define RIGHT_MOTOR_PWM 21
#define RIGHT_MOTOR_IN_PIN1 22
#define RIGHT_MOTOR_IN_PIN2 25
#define RIGHT_MOTOR_CHANNEL 0
#define RIGHT_MOTOR_SPEED 1.0

#define LEFT_MOTOR_PWM 21
#define LEFT_MOTOR_IN_PIN1 26
#define LEFT_MOTOR_IN_PIN2 27
#define LEFT_MOTOR_CHANNEL 1
#define LEFT_MOTOR_SPEED 1.0

#define FRONT_SENSOR_PIN
#define LEFT_SENSOR_PIN
#define FULL_LEFT_SENSOR_PIN
#define RIGHT_SENSOR_PIN
#define FULL_RIGHT_SENSOR_PIN



class Robot{
    public:
        Robot();
        Motor rightMotor;
        Motor leftMotor;
        Vision vision; 
        Microstarter uStart;
        DigitalSensor sensor_f;
        DigitalSensor sensor_r;
        DigitalSensor sensor_fr;
        DigitalSensor sensor_l;
        DigitalSensor sensor_fl;

        void readSensor();
        void fight();    
        void update(Motor &rightMotor, Motor &leftMotor, Vision &vision, Microstarter &uStart, DigitalSensor &sensor_l
        DigitalSensor &sensor_r, DigitalSensor &sensor_fl, DigitalSensor &sensor_fr, DigitalSensor &sensor_f);
        
};

#endif