#include <unity.h>
#include "strategy.h"
#include "Arduino.h"
#include "digital_sensor.h"

void test_move()
{
    Move move(100, 100, 100);
    MotorControl left_motor(0, 0, 0, 1, 0);
    MotorControl right_motor(0, 0, 0, 1, 1);
    bool finished = false;
    int start_time = millis();
    int delta_time;
    int now_ms;

    TEST_ASSERT_EQUAL(false, move.update(left_motor, right_motor));

    while (true)
    {
        ArduinoMock::update_millis();
        finished = move.update(left_motor, right_motor);

        now_ms = millis();
        delta_time = now_ms - start_time;
        if (delta_time > 102)
        {
            // std::cout << delta_time << std::endl;
            TEST_ASSERT_TRUE(finished);
            break;
        }
        else if (delta_time < 100)
        {
            TEST_ASSERT_FALSE(finished);
        }
    }
}

void test_initial_strategy()
{

    Move first_move(100, 100, 100);
    Move second_move(50, -50, 100);
    Move third_move(-50, 50, 100);
    std::list<Move> moves = {first_move, second_move, third_move};
    MotorControl left_motor(0, 0, 0, 1, 0);
    MotorControl right_motor(0, 0, 0, 1, 1);
    InitialStrategy initial_strategy(moves);
    bool finished = false;
    int start_time = millis();
    int delta_time;
    int now_ms;

    TEST_ASSERT_FALSE(initial_strategy.update(left_motor, right_motor));

    while (ArduinoMock::update_millis())
    {

        finished = initial_strategy.update(left_motor, right_motor);

        now_ms = millis();
        delta_time = now_ms - start_time;
        if (delta_time > 304)
        {
            // std::cout << delta_time << std::endl;
            TEST_ASSERT_TRUE(finished);
            break;
        }
        else if (delta_time < 300)
        {
            TEST_ASSERT_FALSE(finished);
        }
        if (delta_time > 25 && delta_time < 75)
        {
            TEST_ASSERT_EQUAL(100, left_motor.power);
            TEST_ASSERT_EQUAL(100, right_motor.power);
        }
        if (delta_time > 125 && delta_time < 175)
        {
            TEST_ASSERT_EQUAL(50, left_motor.power);
            TEST_ASSERT_EQUAL(-50, right_motor.power);
        }
        if (delta_time > 225 && delta_time < 275)
        {
            TEST_ASSERT_EQUAL(-50, left_motor.power);
            TEST_ASSERT_EQUAL(50, right_motor.power);
        }
    }
}
