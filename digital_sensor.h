#ifndef DIGITALSENSOR_H
#define DIGITALSENSOR_H

#include <iostream>

class DigitalSensor{

    public:
        int pin;
        bool state;

        void update ();
        DigitalSensor (int pin);
};


#endif
