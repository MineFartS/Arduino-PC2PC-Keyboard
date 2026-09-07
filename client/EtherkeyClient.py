from serial.tools.list_ports import comports
from serial import Serial
import keyboard

port = comports()[0].device

print(f"\nConnecting via LIVE-Mode on {port}...")
print("Character Relay Active. Every key you type will be forwarded to the Slave PC.")
print("Press 'ESC' to exit and close the connection.\n")

ser = Serial(port, 57600, timeout=0.1)

event_map = {
    'space': ' ',
    'enter': '\n',
    'backspace': '\b',
    'tab': '\t',
}

def on_key_event(e) -> None:

    if e.event_type != 'down':
        return

    key: str = None

    if e.name in event_map:
        key = event_map[e.name]
    
    elif len(e.name) == 1:
        key = e.name

    if key is not None:
        ser.write(key.encode('utf-8'))

try:
    keyboard.hook(on_key_event)
    keyboard.wait('esc')
finally:
    ser.close()

