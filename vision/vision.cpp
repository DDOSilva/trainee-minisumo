#include "vision.h"
#include "digital_sensor.h"

Vision::Vision(){};

void Vision::update(){
    if (sensor_f.state) enemy_position = EnemyPosition::FRONT, latest_position = EnemyPosition::FRONT, return;
    else if(sensor_l.state) enemy_position = EnemyPosition::LEFT, latest_position = EnemyPosition::LEFT, return;
    else if(sensor_r.state) enemy_position = EnemyPosition::RIGHT, latest_position = EnemyPosition::RIGHT, return;
    else if(sensor_fl.state) enemy_position = EnemyPosition::FULL_LEFT, latest_position = EnemyPosition::(LEFT), return;
    else if(sensor_fr.state) enemy_position = EnemyPosition::FULL_RIGHT, latest_position = EnemyPosition::(RIGHT), return;
    //else if(latest_position == EnemyPosition::FULL_LEFT || latest_position == EnemyPosition::LEFT) enemy_position = EnemyPosition::SEARCH_LEFT, return;
    //else if(latest_position == EnemyPosition::FULL_RIGHT || latest_position == EnemyPosition::RIGHT) enemy_position = EnemyPosition::SEARCH_RIGHT, return;
    //else enemy_position = EnemyPosition::SEARCH_RIGHT, return;
}

else if(this->latest_enemy_position == EnemyPosition::RIGHT) this->enemy_position = EnemyPosition::SEARCH_RIGHT), return;
else if(this->latest_enemy_position == EnemyPosition::LEFT) this->enemy_position = EnemyPosition::SEARCH_LEFT), return;
