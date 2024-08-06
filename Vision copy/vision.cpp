#include "vision.h"

Vision::Vision()
{}

void Vision::updateEnemyPosition(DigitalSensor &front_right_sensor, DigitalSensor &front_left_sensor, DigitalSensor &left_sensor, DigitalSensor &right_sensor, AnalogSensor &left_line_sensor, AnalogSensor &right_line_sensor)
{
    if(left_line_sensor.in_line){
        this->line_position = LinePosition::LEFT_LINE;
    }
    else if(right_line_sensor.in_line){
        this->line_position = LinePosition::RIGHT_LINE;
    }
    else if (front_right_sensor.enemy_close && front_left_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FRONT;
        return;
    }
    else if (front_right_sensor.enemy_close && right_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FRONT_RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
        return;
    }
    else if (front_left_sensor.enemy_close && left_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FRONT_LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
        return;
    }
    else if (front_right_sensor.enemy_close)
    {
        this->enemy_position = EnemyPosition::FULL_RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
        return;
    }
    else if (front_left_sensor.enemy_close)
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