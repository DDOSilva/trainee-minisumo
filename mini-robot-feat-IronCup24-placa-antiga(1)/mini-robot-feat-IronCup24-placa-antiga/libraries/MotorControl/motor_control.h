#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

struct MotorConfig
{
    int in1_pin;
    int in2_pin;
    int pwm_pin;
    float speed_const;
    int channel;
    MotorConfig(int pwm_pin, int in1_pin, int in2_pin, float speed_const, int channel);
};

class MotorControl
{
public:
    float max_power = 100;
    int power;
    MotorConfig config;
    void setPower(int power);
    MotorControl(int pwm_pin, int in1_pin, int in2_pin, float speed_const, int channel);
};

#endif