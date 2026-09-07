#include "usb-keyboard.h"

#define RELAY_NODE Serial1

char in_ascii;

void setup() {

    // CRITICAL: We use Serial1 (or the explicit hardware RX/TX UART pins) 
    // because the data is arriving over wires from the Sender Arduino, 
    // not directly from the Master PC's USB cable.
    RELAY_NODE.begin(57600);
    
    // Initialize the underlying Etherkey HID keyboard engine
    Keyboard.begin();
    
    delay(1000);

}

void loop() {

    // Listen for raw keystroke bytes forwarded by the Sender/Relay Arduino
    if (RELAY_NODE.available() <= 0) return;

    in_ascii = RELAY_NODE.read();

    // Enforce basic ASCII boundaries to discard bad data or line noise
    if (in_ascii < 0 || in_ascii > 127) return;
        
    // Immediately pass the raw byte to Etherkey's native typewriter routine.
    // interactive_mode handles converting raw text and structural characters 
    // (\n, \t, \b) into active HID keystrokes for the Slave PC.
    interactive_mode(in_ascii);

}
