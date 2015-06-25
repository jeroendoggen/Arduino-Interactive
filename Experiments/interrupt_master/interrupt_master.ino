// Arduino Interactive: multi camera - interrupt-based master
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

int delayTime = 1000;

void setup()
{
    //TODO                                      // configure the OUTPUT pins
    Serial.begin(9600);                         // use the serial port
                          
}

void loop()
{
  sendCommand();
  delay(delayTime);                              // delay between pictures
}


void sendCommand()
{
// write a one to sync1 pin
// wait a couple of ms
// write a zero to sync1 pin
}
