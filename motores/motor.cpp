#include "motor.h"

Motor::Motor(const int pin):_pin(pin),_speed(130) { //inicializando _pin com valor pin e _speed com valor 130
    
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void Motor::motorOn() {
    digitalWrite(_pin, HIGH);
}

void Motor::motorOff() {
    digitalWrite(_pin, LOW);
}

void Motor::motorSpeed(int speed) {

    _speed = speed;
    analogWrite(_pin, _speed);
}