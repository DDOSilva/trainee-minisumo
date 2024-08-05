#ifndef STRATEGY_H
#define STRATEGY_H

#include <Arduino.h>
#include "vision.h"
#include "motor_control.h"
#include <list>

class Move
{
public:
    int left_motor_power;
    int right_motor_power;
    int time_ms;
    int start_time_ms;
    bool started;
    bool finished;
    bool update(MotorControl &left_motor, MotorControl &right_motor);
    Move(int left_motor_power, int right_motor_power, int time_ms);
};

class InitialStrategy
{
public:
    std::list<Move> moves;
    Move &current_move;
    bool strategy_finished;
    bool update(MotorControl &left_motor, MotorControl &right_motor);
    InitialStrategy(std::list<Move> moves);
};

class AutoStrategy
{
public:
    int left_motor_power;
    int right_motor_power;
    void updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor);
};

InitialStrategy *get_selected_strategy(int pinA, int pinB, int pinC);

#endif