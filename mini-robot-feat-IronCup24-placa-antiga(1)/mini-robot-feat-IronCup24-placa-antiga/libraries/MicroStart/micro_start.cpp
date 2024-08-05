#include "micro_start.h"

uStart::uStart(int signal_pin)
{
    this->signal_pin = signal_pin;
    this->state = uStartState::STOP;
}

void uStart::update()
{
    bool pin_read = digitalRead(this->signal_pin);   
    if (pin_read == true)
    {
        this->state = uStartState::START;
    }
    else
    {
        this->state = uStartState::STOP;
    }
}