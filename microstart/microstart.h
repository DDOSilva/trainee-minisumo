#ifndef MICROSTARTER_H
#define MICROSTARTER_H

#include <iostream>

class Microstarter {
    
    public:
        bool signal;
        const int pin;
        void uptade();
        void Microstarter(const int pin);

};

#endif