#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include <iostream>

class Motor {
    
    private:
        int _speed;
        const int _pin1, _pin2;
        bool statePin;
    public:
        void motorOn();
        void motorOff();
        void motorSpeed(int speed = 130);
        
        void update ();
        Motor (const int pin1, pin2);

};

#endif