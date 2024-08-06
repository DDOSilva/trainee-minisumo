#ifndef VISION_H
#define VISION_H

#include "digital_sensor.h"
#include "analog_sensor.h"
#include <Arduino.h>

#define DISTANCE_LIMIT_CM 20

namespace EnemyPosition
{
    enum Pos
    {
        LEFT,
        RIGHT,
        FRONT,
        FULL_LEFT,
        FULL_RIGHT,
        SEARCH_LEFT,
        SEARCH_RIGHT,
        FRONT_LEFT,
        FRONT_RIGHT
    };
}
namespace LinePosition{
    enum Pos{
        LEFT_LINE,
        RIGHT_LINE
    };
}

class Vision
{
public:
    EnemyPosition::Pos enemy_position;
    EnemyPosition::Pos latest_enemy_position;
    LinePosition::Pos line_position;

    void updateEnemyPosition(DigitalSensor &front_right_sensor, DigitalSensor &front_left_sensor, DigitalSensor &left_sensor, DigitalSensor &right_sensor, AnalogSensor &left_line_sensor, AnalogSensor &right_line_sensor);
    Vision();
};

#endif