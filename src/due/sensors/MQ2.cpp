#include <Arduino.h>
#include "Pinouts.h"

bool gasDetected() {
    if (analogRead(MQ2_INPUT_ANALOG) >= 140) {
        Serial.println("SMOKE!");
    }
}
