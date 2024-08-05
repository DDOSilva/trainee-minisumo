#ifndef ARDUINO_H
#define ARDUINO_H

extern int dac_write[40];
void dacWrite(int pin, int pwm);

extern int dac_write[40];
void ledcWrite(int channel, int pwm);

extern long int millis_time;

#endif