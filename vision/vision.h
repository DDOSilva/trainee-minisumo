#ifndef VISION_H
#define VISION_H
#include "digital_sensor.h"

namespace EnemyPosition {
    enum position {
        FRONT, // 0
        LEFT, // 1
        FULL_LEFT, //2
        RIGHT, //3
        FULL_RIGHT, //4
        SEARCH_LEFT, //5
        SEARCH_RIGHT //6
    };
};

class Vision{
    public:

    EnemyPosition::position enemy_position, latest_position;

    Vision();

    void update(DigitalSensor sensor_l, DigitalSensor sensor_fl, DigitalSensor sensor_r, DigitalSensor sensor_fr, DigitalSensor sensor_f);

};


#endif