#include "motor.h"

Motor::Motor(const int pinA):_pin1(pinA),_speed(130) { //inicializando _pin com valor pin e _speed com valor 130

    pinMode(_pin1, OUTPUT); //definindo como entrada
    digitalWrite(_pinA, LOW); //desligado
}

void Motor::motorOn() {
    digitalWrite(_pinA, HIGH);
}

void Motor::motorOff() {
    digitalWrite(_pinA, LOW);
}

void Motor::motor1Speed(int speed) {

    _speed = speed;
    analogWrite(_pinA, _speed);
}