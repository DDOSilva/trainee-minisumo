#include "vision.h"
#include "digital_sensor.h"

Vision::Vision(){};

void Vision::update(){
    if (this->sensor_f.state) this->enemy_position = EnemyPosition::FRONT, this->latest_position = EnemyPosition::FRONT, return;
    else if(this->sensor_l.state) this->enemy_position = EnemyPosition::LEFT, this->latest_position = EnemyPosition::LEFT, return;
    else if(this->sensor_r.state) this->enemy_position = EnemyPosition::RIGHT, this->latest_position = EnemyPosition::RIGHT, return;
    else if(this->sensor_fl.state) this->enemy_position = EnemyPosition::FULL_LEFT, this->latest_position = EnemyPosition::LEFT, return;
    else if(this->sensor_fr.state) this->enemy_position = EnemyPosition::FULL_RIGHT, this->latest_position = EnemyPosition::RIGHT, return;
    else if(this->latest_position == EnemyPosition::LEFT) this->enemy_position = EnemyPosition::SEARCH_LEFT, return;
    else if(this->latest_position == EnemyPosition::RIGHT) this->enemy_position = EnemyPosition::SEARCH_RIGHT, return;
}

