#include <Arduino.h>
#include "digital_sensor.h"

DigitalSensor::DigitalSensor(int pin)
{
    this->pin = pin;
};


int DigitalSensor::readSensor()
{
    this->raw_reading = digitalRead(this->pin);
    this->enemy_close = this->raw_reading == 1 ? true : false;
    return this->raw_reading;
}