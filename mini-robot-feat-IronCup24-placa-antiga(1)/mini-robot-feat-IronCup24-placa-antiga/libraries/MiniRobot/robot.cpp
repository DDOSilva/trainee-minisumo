
#include "robot.h"
#include <Arduino.h>

Robot::Robot() : front_sensor(FRONT_SENSOR_PIN),
                    left_sensor(LEFT_SENSOR_PIN),
                    right_sensor(RIGHT_SENSOR_PIN),
                    full_left_sensor(FULL_LEFT_SENSOR_PIN),
                    full_right_sensor(FULL_RIGHT_SENSOR_PIN),
                    left_line_sensor(left_line_sensor_pin),
                    right_line_sensor(right_line_sensor_pin),
                    right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN, RIGHT_MOTOR_SPEED_CONST, RIGHT_MOTOR_CHANNEL),
                    left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN, LEFT_MOTOR_SPEED_CONST, LEFT_MOTOR_CHANNEL),
vision(), auto_strategy(), ustart(MICRO_START_SIGNAL_PIN)
{
    this->robot_state = RobotState::AWAITING_START;

}

void Robot::readSensors()
{
    this->front_sensor.readSensor();
    this->left_sensor.readSensor();
    this->right_sensor.readSensor();
    this->full_left_sensor.readSensor();
    this->full_right_sensor.readSensor();
    this->left_line_sensor.inLine();
    this->right_line_sensor.inLine();
}

void Robot::printSensors()
{
    /*
        A leitura esta bem posta, agora basta inserir os dados do movimento setado na initial strategy e organizar em linha e não com a quebra
        da mesma que esta.
    */
    //MicroStart
    Serial.println("\t\tMS");
    Serial.print(this->ustart.state);
    // Serial.println();
    // Serial.print("_________________________________________");
    // Serial.println();

    //Sensores
    Serial.println("\t\tSS");
    Serial.print("FL:");
    Serial.print(this->full_left_sensor.raw_reading);
    Serial.print("\t");
    Serial.print("L:");
    Serial.print(this->left_sensor.raw_reading);
    Serial.print("\t");
    Serial.print("F:");
    Serial.print(this->front_sensor.raw_reading);
    Serial.print("\t");
    Serial.print("R:");
    Serial.print(this->right_sensor.raw_reading);
    Serial.print("\t");
    Serial.print("FR:");
    Serial.print(this->full_right_sensor.raw_reading);
    // 'Serial.println();
    // Serial.print("_________________________________________");
    // Serial.println();'


    //motores
    Serial.println("\t\tMT");
    Serial.print("MD:");
    Serial.print(this->left_motor.power);
    Serial.print("\t");
    Serial.print("ME:");
    Serial.print(this->right_motor.power);
    // 'Serial.println();
    // Serial.print("_________________________________________");
    // Serial.println();'


    //dipswitch
    Serial.println("\t\tDS");
    Serial.print("A:");
    Serial.print(digitalRead(STRATEGY_PIN_A));
    Serial.print("\t");
    Serial.print("B:");
    Serial.print(digitalRead(STRATEGY_PIN_B));
    Serial.print("\t");
    Serial.print("C:");
    Serial.print(digitalRead(STRATEGY_PIN_C));
    // Serial.println();
    // Serial.print("_________________________________________");
    // Serial.println();
}

void Robot::update()
{
    this->ustart.update();
    this->readSensors();
    this->vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, this->right_sensor, this->left_line_sensor, this->right_line_sensor);
    this->printSensors();
    this->fight();
}

void Robot::fight()
{
    bool initial_strategy_finished = false;
    switch (this->robot_state)
    {

    case RobotState::AWAITING_START:
        if (this->ustart.state == uStartState::START)
        {
            this->robot_state = RobotState::INITIAL_STRATEGY;
            this->initial_strategy = get_selected_strategy(STRATEGY_PIN_A, STRATEGY_PIN_B, STRATEGY_PIN_C);
        }
        break;

    case RobotState::INITIAL_STRATEGY:
        initial_strategy_finished = this->initial_strategy->update(this->left_motor, this->right_motor);
        if (initial_strategy_finished)
        {
            this->robot_state = RobotState::AUTO_STRATEGY;
        }
        if (this->ustart.state == uStartState::STOP)
        {
            this->robot_state = RobotState::STOPPED;
        }
        break;

    case RobotState::AUTO_STRATEGY:
        this->auto_strategy.updateMotors(this->vision, this->left_motor, this->right_motor);
        if (this->ustart.state == uStartState::STOP)
        {
            this->robot_state = RobotState::STOPPED;
        }
        break;

    case RobotState::STOPPED:
        left_motor.setPower(0);
        right_motor.setPower(0);
        break;
    default:
        Serial.println("UNKNOWN BEHAVIOR");
    }

}