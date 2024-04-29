#ifndef VISION_H
#define VISION_H
#include <string>

class Vision{
    public:
    int pin_fl, pin_l, pin_f, pin_r, pin_fr;
    std::string enemy_position, last_position;

    Vision(int pin_fl, int pin_l, int pin_f, int pin_r, int pin_fr);

    void update();

};


#endif