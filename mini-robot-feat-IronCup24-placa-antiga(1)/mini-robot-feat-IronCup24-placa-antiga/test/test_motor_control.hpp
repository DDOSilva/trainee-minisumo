#include <unity.h>
#include "motor_control.h"

#ifdef PIO_UNIT_TESTING
// #include "ArduinoFake.h"
// #include "EspFake.h"
#include "Arduino.h"
#else
#include "Arduino.h"
#endif

void test_motor_control()
{
    MotorControl test_motor(1, 2, 3, 1.0, 0);

    test_motor.setPower(100);
    TEST_ASSERT_TRUE(digital_write[test_motor.config.in1_pin]);
    TEST_ASSERT_FALSE(digital_write[test_motor.config.in2_pin]);
    TEST_ASSERT_EQUAL(255, dac_write[test_motor.config.channel]);

    test_motor.setPower(-100);
    TEST_ASSERT_FALSE(digital_write[test_motor.config.in1_pin]);
    TEST_ASSERT_TRUE(digital_write[test_motor.config.in2_pin]);
    TEST_ASSERT_EQUAL(255, dac_write[test_motor.config.channel]);

    MotorControl test_motor2(1, 2, 3, -1.0, 1);

    test_motor2.setPower(100);
    TEST_ASSERT_FALSE(digital_write[test_motor2.config.in1_pin]);
    TEST_ASSERT_TRUE(digital_write[test_motor2.config.in2_pin]);

    TEST_ASSERT_EQUAL(255, dac_write[test_motor2.config.channel]);

    test_motor2.setPower(-100);
    TEST_ASSERT_TRUE(digital_write[test_motor2.config.in1_pin]);
    TEST_ASSERT_FALSE(digital_write[test_motor2.config.in2_pin]);
    TEST_ASSERT_EQUAL(255, dac_write[test_motor2.config.channel]);

    test_motor2.setPower(50);
    TEST_ASSERT_FALSE(digital_write[test_motor2.config.in1_pin]);
    TEST_ASSERT_TRUE(digital_write[test_motor2.config.in2_pin]);

    TEST_ASSERT_EQUAL(255 / 2, dac_write[test_motor2.config.channel]);

    test_motor2.setPower(-50);
    TEST_ASSERT_TRUE(digital_write[test_motor2.config.in1_pin]);
    TEST_ASSERT_FALSE(digital_write[test_motor2.config.in2_pin]);
    TEST_ASSERT_EQUAL(255 / 2, dac_write[test_motor2.config.channel]);

    MotorControl test_motor3(1, 2, 3, 0.5, 2);

    test_motor3.setPower(100);
    TEST_ASSERT_TRUE(digital_write[test_motor3.config.in1_pin]);
    TEST_ASSERT_FALSE(digital_write[test_motor3.config.in2_pin]);
    TEST_ASSERT_EQUAL(255 / 2, dac_write[test_motor3.config.channel]);

    test_motor3.setPower(-100);
    TEST_ASSERT_FALSE(digital_write[test_motor3.config.in1_pin]);
    TEST_ASSERT_TRUE(digital_write[test_motor3.config.in2_pin]);
    TEST_ASSERT_EQUAL(255 / 2, dac_write[test_motor3.config.channel]);

    test_motor3.setPower(50);
    TEST_ASSERT_TRUE(digital_write[test_motor3.config.in1_pin]);
    TEST_ASSERT_FALSE(digital_write[test_motor3.config.in2_pin]);
    TEST_ASSERT_EQUAL(255 / 4, dac_write[test_motor3.config.channel]);

    test_motor3.setPower(-50);
    TEST_ASSERT_FALSE(digital_write[test_motor3.config.in1_pin]);
    TEST_ASSERT_TRUE(digital_write[test_motor3.config.in2_pin]);
    TEST_ASSERT_EQUAL(255 / 4, dac_write[test_motor3.config.channel]);
}