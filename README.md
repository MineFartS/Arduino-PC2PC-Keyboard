# Arduino PC2PC Keyboard
#### Send keystrokes from one computer to another

#### UNFINISHED

[![](.github/diagram1.svg)](.github/Diagram.md)

---
### Hardware

- **[Client Computer](client/README.md)** \
    *Sends serialized keystrokes to the Master Node*
<br>

- **[Master Node](master/README.md)** *(Arduino Leonardo)* \
    *Forwards serial input from the Client Computer to the Slave Node*
<br>

- **[Slave Node](slave/README.md)** *(Arduino Leonardo)* \
    *Parses the serial input from the Master Node and emulates a physical keyboard for the Target Computer*
<br>

- **Target Computer** \
    *Receives keystrokes from the Slave Node*

---
### Flashing

1. Connect Arduino Leonardo Node to the Windows Computer
2. Go to the node directory *(master, slave)*
2. Run `flash.bat`

---

