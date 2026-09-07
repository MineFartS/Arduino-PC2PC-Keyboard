#define MASTER_PC Serial
#define INJECTOR_NODE Serial1

void setup() {

    // 1. Listen to the Master PC over the USB cable (Must match Python's 57600)
    MASTER_PC.begin(57600); 
    
    // 2. Talk to the Etherkey Arduino via hardware TX/RX pins (Must match Etherkey's 57600)
    INJECTOR_NODE.begin(57600);
    
    // Wait for the USB serial connection to stabilize
    while (!MASTER_PC) { ; } 
}

void loop() {

    // Check if Python sent a keystroke over USB
    if (MASTER_PC.available() > 0) {
        
        // Read the character from USB
        char key = Serial.read();
        
        // Forward it out of the physical TX pin to Etherkey's RX pin
        INJECTOR_NODE.print(key);

    }

}
