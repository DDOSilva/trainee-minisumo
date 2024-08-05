#include "Arduino.h"

long int millis_time = 0;
bool ArduinoMock::update_millis()
{
    millis_time++;
    return true;
}

bool digital_read[40] = { 0 };
void ArduinoMock::set_digital_read(int pin, bool state)
{
    digital_read[pin] = state;
}

long unsigned int millis()
{
    return millis_time;
}

int analogRead(int pin)
{
    return 2000;
}

int digitalRead(int pin)
{
    return digital_read[pin];
}

bool digital_write[40] = { 0 };
void digitalWrite(int pin, bool state)
{
    digital_write[pin] = state;
}

int dac_write[40] = { 0 };
void dacWrite(int pin, int pwm)
{
    dac_write[pin] = pwm;
}

void ledcWrite(int channel, int pwm)
{
    dac_write[channel] = pwm;
}

void ArduinoSerial::begin(int baud) {};
void ArduinoSerial::print(int val)
{
    std::cout << val;
};
void ArduinoSerial::println(int val)
{
    std::cout << val << std::endl;
};
void ArduinoSerial::println(std::string txt)
{
    std::cout << txt << std::endl;
};
void ArduinoSerial::print(std::string txt)
{
    std::cout << txt;
};
void ArduinoSerial::write(int c) {};
void ArduinoSerial::flush() {};
void ArduinoSerial::end() {};

void pinMode(int pin, int mode) {};

void delay(int time) {}

ArduinoSerial Serial;
