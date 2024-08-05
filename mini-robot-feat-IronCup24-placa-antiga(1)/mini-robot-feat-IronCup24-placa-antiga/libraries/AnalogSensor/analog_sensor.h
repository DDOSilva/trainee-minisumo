//Declaração da classe

#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "define.h"

class AnalogSensor{
    public:
        int pin;
        int raw_reading; //leitura crua dos sensores
        int trash_hold; //limite arbitário para valor lido
        int in_line; //recebe o retorno de inLine();

        AnalogSensor(int pin);
        int inLine();
};

#endif //ANALOG_SENSOR_H