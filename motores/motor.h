#ifndef MOTOR_H
#define MOTOR_H

class Motor {
    
    public:
        int speed;
        int pin_pwm;
        int pin_Ch;
        int pin_1;
        int pin_2; 
        int cSpeed; //constant speed
        int speed_max = 100;

        void update ();
        Motor (int pin_ch, int pin_1, int pin_2 int pin_pwm, int speed);
        void setspeed(int speed);

};

#endif