#!/usr/bin/python

import argparse
import os
import sys
import serial
import serial.tools.list_ports

def get_serial_port():
    """Finds the first available COM port automatically."""
    ports = list(serial.tools.list_ports.comports())
    if not ports:
        print("Error: No USB microcontrollers found! Check your connection.")
        sys.exit(1)
    # Returns the first found port (e.g., 'COM3')
    return ports[0].device

def send_file_over_serial(port, filepath):
    """Opens the serial port and streams the file contents to the microcontroller."""
    if not os.path.exists(filepath):
        print(f"Error: File '{filepath}' not found.")
        return

    print(f"\nConnecting via FILE-Mode on {port}...")
    try:
        # Match the 57600 baud rate from your original script
        with serial.Serial(port, 57600, timeout=1) as ser:
            with open(filepath, 'rb') as f:
                print(f"Sending {filepath}...")
                ser.write(f.read())
            print("File transmission complete.")
    except Exception as e:
        print(f"Serial Error: {e}")

def enter_live_mode(port):
    """Opens an interactive terminal session with the microcontroller."""
    print(f"\nConnecting via LIVE-Mode on {port}...")
    print("Type your commands. Press Ctrl+C to exit.\n")
    try:
        with serial.Serial(port, 57600, timeout=0.1) as ser:
            while True:
                # Read keyboard input from user console
                if sys.stdin.isatty():
                    user_input = input(">> ") + "\n"
                    ser.write(user_input.encode('utf-8'))
                
                # Check for response from microcontroller
                if ser.in_waiting:
                    response = ser.read(ser.in_waiting).decode('utf-8', errors='ignore')
                    print(response, end='')
    except KeyboardInterrupt:
        print("\nExiting LIVE-Mode.")
    except Exception as e:
        print(f"Serial Error: {e}")

def parseArguments():
    parser = argparse.ArgumentParser(description='USB-Net-Keyboard Client 0.01 (Windows/Local Serial Patch)')
    parser.add_argument("-l", "--live", action='store_true', help="Live-Mode interaction with Net-Keyboard")
    parser.add_argument("-f", "--file", help="File-Mode send a command file")
    args = parser.parse_args()

    # Automatically identify your Arduino/Microcontroller port
    port = get_serial_port()

    if args.live:
        enter_live_mode(port)
    elif args.file:
        send_file_over_serial(port, args.file)
    else:
        print("Please use the following combinations:\n")
        print("LIVE-Mode: python etherkeyclient.py -l")
        print("FILE-Mode: python etherkeyclient.py -f FILE\n")

def main():
    parseArguments()

if __name__=='__main__':
    main()
