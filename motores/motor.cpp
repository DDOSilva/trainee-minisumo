#include <iostream>
#include <Arduino.h>
#include "motor.h"

Motor::Motor(int pin_ch, int pin_1, int pin_2 int pwm, int cSpeed) {}
    this->pin_ch = pin_ch;
    this->cSpeed = cSpeed;
    this->pwm = pwm;
    this->pin_1 = pin_1;
    this->pin_2 = pin_2;
}

void Motor::setspeed(int speed) {

    this->speed = speed;
    
    float fixSpeed = speed * this->cSpeed; //velocidade fixada sera usada dentro das condições do motor
    int pwm100 = (int)(this->speed_max / (100.0 * 255.0) * ((float)abs(fixSpeed) / 100.0)); //conversao de -255 a 255 para -100 a 100

    if(fixSpeed < 0 && fixSpeed >= -220) { //alternando o estado dos pinos
        digitalWrite(this->pin_1, HIGH);   //quando anda pra tras -> pin 1 ligado
        digitalWrite(this->pin_2, LOW);
    } else if (fixSpeed > 0 && fixSpeed <= 220) {
        digitalWrite(this->pin_1, LOW);    //quando anda pra frente -> pin 2 ligado
        digitalWrite(this->pin_2, HIGH);
    } else
        std::cout << "invalid speed";

    ledcWrite(pin_ch, pwm100); //manda o valor do pwm (de -100 a 100) para o pino channel
}

