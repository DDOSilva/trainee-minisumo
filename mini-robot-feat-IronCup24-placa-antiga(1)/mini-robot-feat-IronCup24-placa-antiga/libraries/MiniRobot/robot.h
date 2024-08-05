#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "micro_start.h"
#include "digital_sensor.h"
#include "analog_sensor.h"
#include "motor_control.h"
#include "vision.h"
#include "strategy.h"

using namespace std;

#define FRONT_SENSOR_PIN 35
#define FULL_RIGHT_SENSOR_PIN 25
#define FULL_LEFT_SENSOR_PIN 13
#define LEFT_SENSOR_PIN 26
#define RIGHT_SENSOR_PIN 34

#define left_line_sensor_pin 12
#define right_line_sensor_pin 14

#define RIGHT_MOTOR_PWM_PIN 21
#define RIGHT_MOTOR_IN1_PIN 19
#define RIGHT_MOTOR_IN2_PIN 18
#define RIGHT_MOTOR_SPEED_CONST 1.0
#define RIGHT_MOTOR_CHANNEL 0

#define LEFT_MOTOR_PWM_PIN 4
#define LEFT_MOTOR_IN1_PIN 17
#define LEFT_MOTOR_IN2_PIN 16
#define LEFT_MOTOR_SPEED_CONST 1.0
#define LEFT_MOTOR_CHANNEL 1

#define MICRO_START_SIGNAL_PIN 2

#define STRATEGY_PIN_A 22
#define STRATEGY_PIN_B 23
#define STRATEGY_PIN_C 33

#define STDBY 5

namespace RobotState
{
  enum States
  {
    AWAITING_START,
    INITIAL_STRATEGY,
    AUTO_STRATEGY,
    STOPPED
  };
}

class Robot
{
public:
  string name = "robot";
  int led_pin = 13;
  RobotState::States robot_state;
  uStart ustart;
  DigitalSensor front_sensor;
  DigitalSensor full_left_sensor;
  DigitalSensor full_right_sensor;
  DigitalSensor left_sensor;
  DigitalSensor right_sensor;
  AnalogSensor left_line_sensor;
  AnalogSensor right_line_sensor;
  MotorControl left_motor;
  MotorControl right_motor;
  Vision vision;
  InitialStrategy* initial_strategy;
  AutoStrategy auto_strategy;

  void readSensors();
  void printSensors();
  void update();
  void fight();

  Robot();
};

#endif