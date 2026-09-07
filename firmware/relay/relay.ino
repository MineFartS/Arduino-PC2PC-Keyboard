
// USB Virtual COM Port connected to your Client PC
#define CLIENT_PORT Serial

// Hardware UART Tx/Rx Pins wired to the Slave Node
#define SLAVE_PORT  Serial1

const uint32_t ETHERKEY_BAUD = 57600;

void setup() {

  // Initialize the native USB subsystem 
  CLIENT_PORT.begin(ETHERKEY_BAUD);
  
  // Initialize physical TX (Pin 1) and RX (Pin 0) 
  SLAVE_PORT.begin(ETHERKEY_BAUD);

}

void loop() {

    // Pipe: Client PC -> Slave Node
    while (CLIENT_PORT.available() > 0) {
        SLAVE_PORT.write(CLIENT_PORT.read());
    }

    // Pipe: Slave Node -> Client PC
    while (SLAVE_PORT.available() > 0) {
        CLIENT_PORT.write(SLAVE_PORT.read());
    }

}
