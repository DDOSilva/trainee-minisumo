#include "digital_sensor.h"

DigitalSensor::DigitalSensor(int pin){
    this->pin = pin;
}

void DigitalSensor::update(){
    this->state = digitalRead(this->pin); //precisa do arduino
}

