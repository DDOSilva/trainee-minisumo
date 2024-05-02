#include <iostream>
#include <arduinho.h>
#include "robot.h"

void setup () {

    Serial.begin(115200);

    pinMode(FRONT_SENSOR_PIN, INPUT);
    pinMode(FULL_RIGHT_SENSOR_PIN, INPUT);
    pinMode(FULL_LEFT_SENSOR_PIN, INPUT);
    pinMode(LEFT_SENSOR_PIN, INPUT);
    pinMode(RIGHT_SENSOR_PIN, INPUT);

    pinMode(RIGHT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_IN_PIN1, OUTPUT);
    pinMode(RIGHT_MOTOR_IN_PIN2, OUTPUT);

    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(LEFT_MOTOR_IN_PIN1, OUTPUT);
    pinMode(LEFT_MOTOR_IN_PIN2, OUTPUT);

    pinMode(MICROSTARTER_PIN, INPUT);

    pinMode(STDBY, OUTPUT);
    digitalWrite(STDBY, HIGH);

    ledcAttachPin(RIGHT_MOTOR_PWM, RIGHT_MOTOR_CHANNEL);
    ledcSetup(RIGHT_MOTOR_CHANNEL, 12000, 8);

    ledcAttachPin(LEFT_MOTOR_PWM, LEFT_MOTOR_CHANNEL);
    ledcSetup(LEFT_MOTOR_CHANNEL, 12000, 8);

}

void loop () {
        static Robot robo;
        robo.fight();
}