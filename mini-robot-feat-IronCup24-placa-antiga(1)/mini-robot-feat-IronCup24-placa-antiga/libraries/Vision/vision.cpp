#include "vision.h"

Vision::Vision()
{}

void Vision::updateEnemyPosition(DigitalSensor &front_sensor, DigitalSensor &full_left_sensor, DigitalSensor &full_right_sensor, DigitalSensor &left_sensor, DigitalSensor &right_sensor, AnalogSensor &left_line_sensor, AnalogSensor &right_line_sensor)
{
    if(left_line_sensor.in_line){
        this->line_position = LinePosition::LEFT_LINE;
    }
    else if(right_line_sensor.in_line){
        this->line_position = LinePosition::RIGHT_LINE;
    }
    else if (front_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FRONT;
        return;
    }
    else if (full_right_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FULL_RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
        return;
    }
    else if (full_left_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FULL_LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
        return;
    }
    else if (right_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
        return;
    }
    else if (left_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
        return;
    }    
    else if (this->latest_enemy_position == EnemyPosition::RIGHT)
    {
        this->enemy_position = EnemyPosition::SEARCH_RIGHT;
        return;
    }
    else if (this->latest_enemy_position == EnemyPosition::LEFT)
    {
        this->enemy_position = EnemyPosition::SEARCH_LEFT;
        return;
    }
}