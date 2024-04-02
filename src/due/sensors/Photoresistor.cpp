#include <Arduino.h>
#include "Pinouts.h"

int readPhotoResistor() {
    analogRead(PHOTORESISTOR_ANALOG);
}
