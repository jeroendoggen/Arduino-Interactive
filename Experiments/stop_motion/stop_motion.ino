// Arduino Interactive: stop-motion example
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

int delayTime = 10000;                            // 10 seconds

void setup()
{
    //TODO                                      // configure the input pins
    //TODO                                      // configure the output pins
    Serial.begin(9600);                         // use the serial port
}

void loop()
{
  takePicture();
  delay(delayTime);                             // delay between pictures
}

void takePicture()
{
// do stuff here
}
