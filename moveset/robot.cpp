#include <iostream>
#include <Arduino.h>

#include "motor.h"
#include "vision.h"
#include "robot.h"
#include "microstart.h"


Moveset::Moveset() {};

void Moveset::update(Motor &rightMotor, Motor &leftMotor, Vision &vision, Microstarter &uStart, DigitalSensor &sensor_l
        DigitalSensor &sensor_r, DigitalSensor &sensor_fl, DigitalSensor &sensor_fr, DigitalSensor &sensor_f) {

    if(vision.enemy_position == EnemyPosition::FRONT){
        rightMotor.setspeed(100);
        leftMotor.setspeed(100);
        return;
    } else if (vision.enemy_position == EnemyPosition::LEFT) {
        rightMotor.setspeed(90);
        leftMotor.setspeed(15);
        return;
    } else if (vision.enemy_position == EnemyPosition::RIGHT) {  
        rightMotor.setspeed(15);
        leftMotor.setspeed(90);
        return;
    } else if (vision.enemy_position == EnemyPosition::FULL_LEFT) {
        rightMotor.setspeed(100);
        leftMotor.setspeed(-100);
        return;
    } else if (vision.enemy_position == EnemyPosition::FULL_RIGHT) {
        rightMotor.setspeed(-100);
        leftMotor.setspeed(100);
        return;
    } else if (vision.enemy_position == EnemyPosition::SEARCH_LEFT) {
        rightMotor.setspeed(80);
        leftMotor.setspeed(5);
        return;
    } else if (vision.enemy_position == EnemyPosition::SEARCH_RIGHT) {
        rightMotor.setspeed(5);
        leftMotor.setspeed(80);
        return;
    }

}