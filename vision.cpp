#include "vision.h"
#include "digital_sensor.cpp"

Vision::Vision(int pin_fl, int pin_l, int pin_f, int pin_r, int pin_fr){
    this->pin_fl = pin_fl;
    this->pin_l = pin_l;
    this->pin_f = pin_f;
    this->pin_r = pin_r;
    this->pin_fr = pin_fr;
}

void Vision::update(){
    DigitalSensor sensor_fl(this->pin_fl);
    DigitalSensor sensor_l(this->pin_l);
    DigitalSensor sensor_f(this->pin_f);
    DigitalSensor sensor_r(this->pin_r);
    DigitalSensor sensor_fr(this->pin_fr);

    if (sensor_f.state) enemy_position = "Front", last_position = "Front";
    else if(sensor_l.state) enemy_position = "Left", last_position = "Left";
    else if(sensor_r.state) enemy_position = "Right", last_position = "Right";
    else if(sensor_fl.state) enemy_position = "Full Left", last_position = "Full Left";
    else if(sensor_fr.state) enemy_position = "Full Right", last_position = "Full Right";
    else enemy_position = "None";
}