# Experiments

## 1. Button Press
This example (button_press.ino) is a skeleton file that you can adapt to control your camera with a pushbutton:
 1. Change the code
 2. Upload to the Arduino
 3. Press the button
 4. The camera should take a picture

## 2. Stop-motion
This example (stop_motion.ino) is a skeleton file that you can adapt to create a stop_motion photoset.
 1. Change the code
 2. Upload to the Arduino
 4. The camera should take a set of pictures in a loop
 
## 3. Multi Camera
It is possible to connect multiple Photomind devices to control multiple camera's at the same time.

The hardware provides connectivity for two options:
 * interrupt-bases: sync1 and sync2 pins (Arduino pins D2, D3)
 * I2C communication: pin 1 and 2 on the "open2" connector (Arduino pins A5/SDA, A5/SCL)

Make sure all your devices share a common ground. (for example using one of the sync pins)

### 3.1. Interrupt-based Multi Camera
We need al least two devices:
 * master: sends the command (write a one to a digital pin)
 * slave: responds to the commands (detect the rising edge and do 'something')

Connection:
 * Connect the sync1 pins of all devices
 * Connect the sync2 pins of all devices
 
How it works:
 * The master writes a zero to pin sync1 (nothing happens)
 * The master write a one to pin sync1 -> the slaves react to the rising edge by running an interrupt service routine.
 
Example code (skeleton): "interrupt_master.ino" and "interrupt_slave.ino"

### 3.2. Master-slave Serial (I2C) Multi Camera
TODO add info
