#include <iostream>
#include <Arduino.h>

#include "motor.h"
#include "vision.h"
#include "robot.h"
#include "microstart.h"



Moveset::Moveset() : rightMotor(RIGHT_MOTOR_PWM, RIGHT_MOTOR_PIN1, ...),
                        f(SENSOR_F),
                        uStart(MICRIS_STARTER...),
{
        this->... = MICROSTART::STOP;
}

void ...::readsensor(){
        this->...sensor.updat();
        .
        .
        .
        .
}

void luta..(){
        this->microstart.update();
        this->readsensor();
        this->vision.updateEnemyPsition(this->f, this->...);
        this->update();


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





//criar uma main separada para pinmode e loop de luta

setup {
        Serial.begin(115200);
pinMode(FRONT_PIN, INPUT);
  pinMode(FULL_RIGHT_PIN, INPUT);
  pinMode(FULL_LEFT_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);

  pinMode(RIGHT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_IN_PIN_1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN_PIN_2, OUTPUT);
  pinMode(LEFT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_IN_PIN_1, OUTPUT);
  pinMode(LEFT_MOTOR_IN_PIN_2, OUTPUT);

  pinMode(MICRO_START_INPUT_PIN, INPUT);

  // pinMode(STDBY, OUTPUT);
  // digitalWrite(STDBY, HIGH);

  ledcAttachPin(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_CHANNEL);
  ledcSetup(RIGHT_MOTOR_CHANNEL, 12000, 8);

  ledcAttachPin(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_CHANNEL);
  ledcSetup(LEFT_MOTOR_CHANNEL, 12000, 8);
        ...
        }

loop{
        static Robot robo;
        robo.luta();
}
