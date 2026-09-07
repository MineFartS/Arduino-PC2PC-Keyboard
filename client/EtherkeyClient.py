from serial.tools import list_ports
from serial import Serial
import sys

# Automatically identify your Arduino/Microcontroller port
ports = list(list_ports.comports())
if not ports:
    print("Error: No USB microcontrollers found! Check your connection.")
    sys.exit(1)
# Returns the first found port (e.g., 'COM3')
port = ports[0].device

print(f"\nConnecting via LIVE-Mode on {port}...")
print("Type your commands. Press Ctrl+C to exit.\n")

ser = Serial(port, 57600, timeout=0.1)

while True:

    # Read keyboard input from user console
    user_input = input(">> ") + "\n"
    ser.write(user_input.encode('utf-8'))
    
    # Check for response from microcontroller
    if ser.in_waiting:
        response = ser.read(ser.in_waiting).decode('utf-8', errors='ignore')
        print(response, end='')
