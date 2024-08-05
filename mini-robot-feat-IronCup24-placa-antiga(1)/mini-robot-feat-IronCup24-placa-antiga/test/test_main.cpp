#include <unity.h>
#include "strategy.h"
#include "robot.h"
#include "Arduino.h"
#include "test_initial_strategy.hpp"
#include "test_robot.hpp"
#include "test_motor_control.hpp"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_move);
    RUN_TEST(test_initial_strategy);

    RUN_TEST(test_robot);
    RUN_TEST(test_motor_control);

    UNITY_END();
}