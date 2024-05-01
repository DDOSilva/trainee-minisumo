#include <iostream>
#include <Arduino.h>

#include "motor.h"
#include "vision.h"
#include "moveset.h"

Moveset::Moveset() {
    
};

void Moveset::Moveset() {

    if(Vision.enemy_position == "Front"){
        for (int i=0, i<=1000, i++){ //poderia usar delay ou chrono?
        rightMotor.setspeed(100);
        leftMotor.setspeed(100);
        }
    } else if (Vision.enemy_position == "Left") {
        for (int i=0, i<=1000, i++){
        rightMotor.setspeed(90);
        leftMotor.setspeed(15);
        }
    } else if (Vision.enemy_position == "Right") {
        for (int i=0, i<=1000, i++){  
        rightMotor.setspeed(15);
        leftMotor.setspeed(90);
        }
    } else if (Vision.enemy_position == "Full Left") {
        for (int i=0, i<=1000, i++){
        rightMotor.setspeed(100);
        leftMotor.setspeed(-100);
        }
    } else if (Vision.enemy_position == "Full Right") {
        for (int i=0, i<=1000, i++){
        rightMotor.setspeed(-100);
        leftMotor.setspeed(100);
        }
    } else if (Vision.enemy_position == "None") {
        if (Vision.last_position == "Right" || Vision.last_position == " Full Right" || Vision.last_position == "Front"){
            rightMotor.setspeed(-70);
            leftMotor.setspeed(70);
        }
        else if(Vision.last_position == "Left" || Vision.last_position == " Full Left"){
            rightMotor.setspeed(70);
            leftMotor.setspeed(-70);
        }
    }

}