#include <Arduino.h>
#include <Keyboard.h>

// Using Port 9 for the touch sensor
const int touchPin = 9;

void setup() {
    
    // INPUT_PULLUP keeps the pin HIGH until ground forces it LOW
    pinMode(touchPin, INPUT_PULLUP);
    
    Keyboard.begin();

}

bool is_touched() {
    return digitalRead(touchPin) == LOW;
}

void loop() {

    if (is_touched()) {

        // Press the Enter key
        Keyboard.write(KEY_RETURN);

        // Block execution until the port is released from ground
        while (is_touched()) {
            delay(10);
        }

    }

}
