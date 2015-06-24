// Arduino Interactive: button t
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

//#include <setup.ino>

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

int piezoValue = 0;
int photoValue = 0;
int potiValue = 0;
int btnState = 0;
int switchState = 0;


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
  delay(delayTime);                              
}

int readSensors()
{
piezoValue = digitalRead(piezo);
photoValue = digitalRead(photo);
potiValue = digitalRead(poti);

btnState = digitalRead(buttonBtn);
switchState = digitalRead(switchBtn);



Serial.print("Piezo-Wert : ");Serial.println(piezoValue);
Serial.print("Photo-Resistor : ");Serial.println(photo);
Serial.print("Potentiometer : ");Serial.println(poti);
Serial.print("Taster : ");Serial.println(buttonBtn);
Serial.print("Schalter : ");Serial.println(switchBtn);
return(true);
}

void takePicture()
{
// do stuff here
}
