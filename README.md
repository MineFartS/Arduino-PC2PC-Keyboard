# Arduino PC2PC Keyboard
#### Send keystrokes from one computer to another

#### UNFINISHED

![](.github/diagram1.svg)

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

