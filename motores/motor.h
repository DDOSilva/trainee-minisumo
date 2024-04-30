#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <iostream>

class Motor {
    
    public:
        int speed;
        int pwm;
        int pinChannel
        int pin1;
        int pin2; 

        void motorSpeed(int speed = 130);
        
        void update ();
        Motor (int pinChannel);

};

#endif