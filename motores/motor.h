#ifndef MOTOR_H
#define MOTOR_H

class Motor {
    
    public:
        int speed;
        int pwm;
        int pin_ch;
        int pin_1;
        int pin_2; 
        int cSpeed; //constant speed
        int speed_max = 100;

        void update ();
        Motor (int pin_ch, int pin_1, int pin_2, int pwm, int cSpeed);
        void setspeed(int speed);

};

#endif
