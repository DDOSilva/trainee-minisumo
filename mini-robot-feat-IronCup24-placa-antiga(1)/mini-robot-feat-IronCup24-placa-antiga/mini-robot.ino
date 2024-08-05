

#include "MiniRobot.h"


#include <Arduino.h>
#include <esp32-hal-ledc.h>

void setup() 
{
  Serial.begin(115200);
  pinMode(RIGHT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_IN1_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_IN1_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_IN2_PIN, OUTPUT);
  pinMode(FRONT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(MICRO_START_SIGNAL_PIN, INPUT);
  pinMode(FULL_RIGHT_SENSOR_PIN, INPUT);
  pinMode(FULL_LEFT_SENSOR_PIN, INPUT);
  pinMode(STRATEGY_PIN_A, INPUT);
  pinMode(STRATEGY_PIN_B, INPUT);  
  pinMode(STRATEGY_PIN_C, INPUT);
    
  pinMode(STDBY,OUTPUT);
  digitalWrite(STDBY,1);

  ledcAttachPin(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_CHANNEL);
  ledcSetup(LEFT_MOTOR_CHANNEL, 12000, 8);

  ledcAttachPin(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_CHANNEL);
  ledcSetup(RIGHT_MOTOR_CHANNEL, 12000, 8);
}

void loop() 
{
  static Robot robot;
  robot.update();
}
