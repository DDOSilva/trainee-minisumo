#include "microstart.h"

Microstarter::Microstarter(const int pin) {
    this->pin = pin;
}

void Microstarter::update() {
    this->signal = digitalRead(this-> pin);
}
