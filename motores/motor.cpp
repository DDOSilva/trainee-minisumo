#include "motor.h"

Motor::Motor(const int pinA):_pin1(pinA),_speed(130) { //inicializando _pin com valor pin e _speed com valor 130
    this->pinA = pinA;
    this->speed = 130; 
}

void Motor::motor1Speed(int speed) {

    this->speed = speed;
    analogWrite(pinA, speed);
}

Motor::update(){
    this->statePin1 = digitalRead(this->statePin1);
    this->statePin2 = digitalRead(this->statePin2);
}