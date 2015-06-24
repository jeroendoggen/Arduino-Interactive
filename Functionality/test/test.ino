// Arduino Interactive: button t
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

int delayTime = 10000;                            // 10 seconds
int buttonState = 0;

int piezo = A0;
int photo = A1;
int poti = A2;
int switchBtn = 11;
int buttonBtn = 12;
int extFlash = 8;
int camTrigger = 9;
int camFocus = 10;


void setup()
{
 Serial.begin(9600);
 pinMode(piezo, INPUT); pinMode(photo, INPUT); pinMode(poti, INPUT); pinMode(switchBtn, INPUT);
 pinMode(buttonBtn, INPUT); pinMode(extFlash, OUTPUT); pinMode(camTrigger, OUTPUT); pinMode(camFocus, OUTPUT);
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
int piezoValue = digitalRead(piezo);
int photoValue = digitalRead(photo);
int potiValue = digitalRead(poti);

  return(buttonState);
}

void takePicture()
{
// do stuff here
}
