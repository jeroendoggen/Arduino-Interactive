// Arduino Interactive: Optocoupler Example
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters


int optoCoupler1 = 10;
// TODO add other pins

int delayTime = 10000;                            // 10 seconds

void setup()
{
  Serial.begin(9600);                             // initialize serial communication:
  pinMode(optoCoupler1, OUTPUT);
  // TODO other pins;
}

void loop()
{
  takePicture();
  delay(delayTime);                               // delay to avoid overloading the serial port buffer  
}


void takePicture()
{
  digitalWrite(led, HIGH);
  delay(100);                                     // wait a short time for the camera to complete
  digitalWrite(led, LOW);
}

void focus()
{
  // TODO: similar to takePicture;
}
