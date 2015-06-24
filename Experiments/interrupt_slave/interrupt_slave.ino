// Arduino Interactive: multi camera - interrupt-based slave
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

// More info: https://www.arduino.cc/en/Reference/AttachInterrupt

void setup()
{
     //TODO                                      // configure the input pins
     //TODO                                      // configure the output pins
     Serial.begin(9600);                         // use the serial port
     // Enable interrupt service routine
}

void loop()
{
  // do nothing
}


void ISR()
{
// do 'something' (for example: take a picture)
}
