//Skript for testing the input-values of the arduino by displaying values in the serial monitor

int delayTime = 4000;                            
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
piezoValue = analogRead(piezo);
photoValue = analogRead(photo);
potiValue = analogRead(poti);

btnState = digitalRead(buttonBtn);
switchState = digitalRead(switchBtn);

Serial.print("Piezo-Wert : ");Serial.println(piezoValue);
Serial.print("Photo-Resistor : ");Serial.println(photoValue);
Serial.print("Potentiometer : ");Serial.println(potiValue);
Serial.print("Taster : ");Serial.println(btnState);
Serial.print("Schalter : ");Serial.println(switchState);
Serial.println("  ");
return(true);
}

void takePicture()
{
// do stuff here
}
