#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

class DigitalSensor
{
public:
    int raw_reading;
    bool enemy_close;
    int pin;
    int readSensor();
    DigitalSensor(int pin);
    
};

#endif