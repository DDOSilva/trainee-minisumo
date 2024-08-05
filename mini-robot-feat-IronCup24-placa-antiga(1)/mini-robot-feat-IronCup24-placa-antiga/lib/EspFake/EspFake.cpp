#include "Arduino.h"

int dac_write[40] = {0};
void dacWrite(int pin, int pwm)
{
    dac_write[pin] = pwm;
}

void ledcWrite(int channel, int pwm)
{
    dac_write[channel] = pwm;
}
