#ifndef MICROSTARTER_H
#define MICROSTARTER_H

#include <iostream>


namespace ms_State {
    enum _state {
        STOP, // 0
        START // 1
    };
}

class Microstarter {
    
    public:
        int pin;
        ms_State::_state state; //state pode ser STOP (0) ou START (1)
        void uptade();
        void Microstarter(int pin);

};

#endif