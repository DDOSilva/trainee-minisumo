#ifndef ARDUINO_H
#define ARDUINO_H

#include <iostream>
#include <string>
#define OUTPUT 0
#define INPUT 1

long unsigned int millis();

int analogRead(int pin);

int digitalRead(int pin);

extern bool digital_write[40];
void digitalWrite(int pin, bool state);

extern int dac_write[40];
void dacWrite(int pin, int pwm);

extern int dac_write[40];
void ledcWrite(int channel, int pwm);

extern long int millis_time;

namespace ArduinoMock
{
    bool update_millis();
    void set_digital_read(int pin, bool state);
};

class ArduinoSerial
{
public:
    void begin(int baud);
    void print(int val);
    void println(int val);
    void print(std::string txt);
    void println(std::string txt);
    void write(int c);
    void flush();
    void end();
    // ArduinoSerial(){};
};

void pinMode(int pin, int mode);

void delay(int time);

extern ArduinoSerial Serial;

#endif