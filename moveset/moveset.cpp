#include <iostream>
#include <Arduino.h>

#include <motor.h>
#include <vision.h>
#include <moveset.h>

Moveset::Moveset() {
    
};

void Moveset::Moveset() {

    if(Vision.enemy_position == "Front"){
        rightMotor.setspeed(100);
        leftMotor.setspeed(100);
    } else if (Vision.enemy_position == "Full left") {
        rightMotor.setspeed(100);
        leftMotor.setspeed(-100);
    } else if (Vision.enemy_position == "Full right") {
        rightMotor.setspeed(-100);
        leftMotor.setspeed(100);
    } else if (Vision.enemy_position == "Left") {
        rightMotor.setspeed(90);
        leftMotor.setspeed(-15);
    } else if (Vision.enemy_position == "Right") {
        rightMotor.setspeed(-15);
        leftMotor.setspeed(90);
    }

}