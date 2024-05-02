#include <iostream>
#include <Arduino.h>

#include "motor.h"
#include "vision.h"
#include "robot.h"
#include "microstart.h"



Moveset::Moveset() : rightMotor(RIGHT_MOTOR_PWM, RIGHT_MOTOR_IN_PIN1, RIGHT_MOTOR_IN_PIN2, RIGHT_MOTOR_SPEED, RIGHT_MOTOR_CHANNEL),
                        leftMotor(LEFT_MOTOR_PWM, LEFT_MOTOR_IN_PIN1, LEFT_MOTOR_IN_PIN2, LEFT_MOTOR_SPEED, LEFT_MOTOR_CHANNEL),
                        sensor_f(FRONT_SENSOR_PIN),
                        sensor_l(LEFT_SENSOR_PIN),
                        sensor_fl(FULL_LEFT_SENSOR_PIN),
                        sensor_r(RIGHT_SENSOR_PIN),
                        sensor_fr(FULL_RIGHT_SENSOR_PIN),
                        uStart(MICROSTARTER_PIN)
{
        this->uStart = Microstarter::STOP;
}

void Moveset::readSensor() {
        this->sensor_f.update();
        this->sensor_l.update();
        this->sensor_fl.update();
        this->sensor_r.update();
        this->sensor_fr.update();
}

void Moveset::fight() {
        this->microstart.update();
        this->readsensor();
        this->vision.update(this->sensor_f, this->sensor_l, this->sensor_fl, this->sensor_r, this->sensor_fr);
        this->update();
}

void Moveset::update(Motor &rightMotor, Motor &leftMotor, Vision &vision, Microstarter &uStart, DigitalSensor &sensor_l
        DigitalSensor &sensor_r, DigitalSensor &sensor_fl, DigitalSensor &sensor_fr, DigitalSensor &sensor_f) {
    
    if(uStart.update == START) { 
        if(this->vision.enemy_position == EnemyPosition::FRONT){
            rightMotor.setspeed(100);
            leftMotor.setspeed(100);
            return;
        } else if (this->vision.enemy_position == EnemyPosition::LEFT) {
            rightMotor.setspeed(90);
            leftMotor.setspeed(15);
            return;
        } else if (this->vision.enemy_position == EnemyPosition::RIGHT) {  
            rightMotor.setspeed(15);
            leftMotor.setspeed(90);
            return;
        } else if (this->vision.enemy_position == EnemyPosition::FULL_LEFT) {
            rightMotor.setspeed(100);
            leftMotor.setspeed(-100);
            return;
        } else if (this->vision.enemy_position == EnemyPosition::FULL_RIGHT) {
            rightMotor.setspeed(-100);
            leftMotor.setspeed(100);
            return;
        } else if (this->vision.enemy_position == EnemyPosition::SEARCH_LEFT) {
            rightMotor.setspeed(80);
            leftMotor.setspeed(5);
            return;
        } else if (this->vision.enemy_position == EnemyPosition::SEARCH_RIGHT) {
            rightMotor.setspeed(5);
            leftMotor.setspeed(80);
            return;
        }
    } else if (uStart.update == STOP) {
        rightMotor.setspeed(0);
        leftMotor.setspeed(0);
        return;
    }

}