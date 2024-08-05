#include <unity.h>
#include "strategy.h"
#include "robot.h"
#include "Arduino.h"

void test_robot()
{
    int now_ms, delta_time_ms;
    Move first_move(100, 100, 100);
    Move second_move(50, -50, 100);
    Move third_move(-50, 50, 100);
    std::list<Move> moves = {first_move, second_move, third_move};
    InitialStrategy initial_strategy(moves);

    Robot robot;

    TEST_ASSERT_EQUAL(RobotState::AWAITING_START, robot.robot_state);
    robot.update();
    TEST_ASSERT_EQUAL(RobotState::AWAITING_START, robot.robot_state);

    ArduinoMock::set_digital_read(MICRO_START_SIGNAL_PIN, true);
    robot.update();
    TEST_ASSERT_EQUAL(RobotState::INITIAL_STRATEGY, robot.robot_state);

    robot.initial_strategy = &initial_strategy;

    int start_time = millis();
    do
    {
        now_ms = millis();
        delta_time_ms = now_ms - start_time;
        if (delta_time_ms < 300)
        {
            // Serial.println(delta_time_ms);
            // Serial.println(robot.robot_state);
            TEST_ASSERT_EQUAL(RobotState::INITIAL_STRATEGY, robot.robot_state);
        }

        robot.update();

    } while (delta_time_ms <= 300 && ArduinoMock::update_millis());

    // Serial.println(delta_time_ms);
    // Serial.println(robot.robot_state);

    TEST_ASSERT_EQUAL(RobotState::AUTO_STRATEGY, robot.robot_state);

    ArduinoMock::set_digital_read(MICRO_START_SIGNAL_PIN, false);
    robot.update();
    TEST_ASSERT_EQUAL(RobotState::STOPPED, robot.robot_state);
}
