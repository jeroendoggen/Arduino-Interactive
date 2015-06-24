// Arduino Interactive: button t
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

int delayTime = 10000;                            // 10 seconds
int buttonState = 0;

void setup()
{
    //TODO                                      // configure the input pins
    //TODO                                      // configure the output pins
    Serial.begin(9600);                         // use the serial port
}

void loop()
{
  if(readSensors() == true)
  {
    takePicture();
  }
  delay(delayTime);                              // delay between pictures
}

int readSensors()
{
//PSEUDO code:
// read the sensors here

  return(buttonState);
}

void takePicture()
{
// do stuff here
}
