#include <iostream>
#include <Arduino.h>
#include "microstart.h"

Microstarter::Microstarter(int pin) {
  //o robô ja está ligado, o que deve dizer se ele pode começar a funcionar é o microstart portanto, inicializamos ele como stop 
    this->pin = _state::STOP;
}

void Microstarter::update() {
  //checar se está recebendo sinal do controle ou não para ligar
    if (digitalRead(int pin)) 
        this->state = _state::START;
    else   
        this->state = _state::STOP;
    
}
