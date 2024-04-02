#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>
#include "Pinouts.h"

// Servo setup
Servo servo;
uint8_t servo_pos;

/// @brief Function to properly set the position of the servo (given by the esp32-cam). Given 18 increments to increase time:movement ratio
/** @param type {
 *  r => move
 *  l => left
 *  s => sets to the start position (0)
 *  m => middle
 *  e => end
 *  c => custom
 *  }
 **/
void servoSet(char type, int degree)
{
    switch (type)
    {
    case 'r':
        servo_pos > 170 ? servo_pos = servo_pos + 10 : servo_pos = 180;
        break;
    case 'l':
        servo_pos >= 5 ? servo_pos = servo_pos - 10 : servo_pos = 0;
        break;
    case 's':
        servo_pos = 0;
        break;
    case 'm':
        servo_pos = 90;
        break;
    case 'e':
        servo_pos = 180;
        break;
    case 'c':
        (degree >= 0 && degree <= 180) ? servo_pos = degree : servo_pos = 0;
        break;
    default:
        servo_pos = 0;
        break;
    }
}

/// @brief Give the last set position by the servo
/// @param req
/// @return servo location in degrees. the reason why '00' is added is for the web server to know that the servo doesnt have a value and something is wrong
int servoRead()
{
    return (servo.read()) ? servo.read() : (int)00 + servo_pos;
}

/// @brief Its used to write the value of the sensor position from the servoSet() function
void servoMove()
{
    servo.write(servo_pos);
}
