#include <iostream>
#include <Arduino.h>
#include "microstart.h"

Microstarter::Microstarter(int pin) {
  //o robô ja está ligado, o que deve dizer se ele pode começar a funcionar é o microstart portanto, inicializamos ele como stop 
    this->pin = pin;
    this->state = ms_State::STOP;
}

void Microstarter::update() {
  //checar se está recebendo sinal do controle ou não para ligar
    if (digitalRead(this->pin)) 
        this->state = ms_State::START;
    else   
        this->state = ms_State::STOP;

}
