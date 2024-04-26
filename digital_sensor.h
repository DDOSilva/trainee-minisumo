#ifndef DIGITALSENSOR_H
#define DIGITALSENSOR_H

#include <iostream>

class DigitalSensor{

    public:
        int pin;
        bool state;

        void see ();
        DigitalSensor (int pin);
};


#endif
