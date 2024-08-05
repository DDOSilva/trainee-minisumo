#ifndef MICRO_START_H
#define MICRO_START_H

#include "Arduino.h"

namespace uStartState
{
    enum States
    {
        START,
        STOP
    };
}

class uStart
{
public:
    int signal_pin;
    uStartState::States state;
    void update();
    uStart(int signal_pin);
};

#endif