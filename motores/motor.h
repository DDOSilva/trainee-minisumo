#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <iostream>

class Motor {
    
    public:
        int speed, pwm;
        const int pinChannel, pin1, pin2; 
        bool statePin1, statePin2;

        void motorSpeed(int speed = 130);
        
        void update ();
        Motor (const int pinChannel);

};

#endif