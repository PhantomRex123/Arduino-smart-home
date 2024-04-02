#include <Arduino.h>
#include <NewPing.h>
#include "Pinouts.h"


NewPing sonar(ULTRASONIC_INPUT_TRIG, ULTRASONIC_INPUT_ECHO, MAX_DISTANCE);
void ultrasonic_get_distance() {
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
}
