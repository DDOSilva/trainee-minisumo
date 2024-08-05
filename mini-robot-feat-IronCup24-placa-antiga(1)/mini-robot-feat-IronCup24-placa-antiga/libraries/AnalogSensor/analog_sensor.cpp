//Definição da classe

#include "analog_sensor.h"

//Construtor
AnalogSensor::AnalogSensor(int pin){
    pinMode(this->pin, INPUT);
    this->pin = pin;
    this->trash_hold = 0; //Ler sensores para delimitar limite aqui
    this->in_line = 0;
}

//Leitura dos sensores
int AnalogSensor::inLine(){
    this->raw_reading = analogRead(this->pin);

    if(raw_reading >= trash_hold) return this->in_line = 1;
    else return this->in_line = 0;
}