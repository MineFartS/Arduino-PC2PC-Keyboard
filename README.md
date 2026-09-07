# Arduino PC2PC Keyboard
#### Send keystrokes from one computer to another

#### UNFINISHED

[![](.github/diagram1.svg)](.github/Diagram.md)

---
### Hardware

- **[Master Computer](client)** \
    *Sends serialized keystrokes to the Relay Node*
<br>

- **[Relay Node](firmware/relay)** *(Arduino Leonardo)* \
    *Forwards serial input from the Master Computer to the Injector Node*
<br>

- **[Injector Node](firmware/injector)** *(Arduino Leonardo)* \
    *Parses the serial input from the Relay Node and emulates a physical keyboard for the Slave Computer*
<br>

- **Slave Computer** \
    *Receives keystrokes from the Slave Node*

---
### Flashing

1. Connect Arduino Leonardo Node to the Windows Computer
2. Go to the firmware directory *(relay, injector)*
2. Run `flash.bat`

---

