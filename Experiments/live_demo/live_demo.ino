// Arduino Interactive: Live Demo
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

// This code was tested with Fotomind 2.0 (not Fotomind Mini)

// Optocouplers:
int flashPin = 6;
int shutterPin = 7;
int focusPin = 8;

// leds:
int ledPin1 = 2;
int ledPin2 = 3;

// buttons:
int buttonPin1 = 4;
int buttonPin2 = 5;

// buttonsStates:
int stateButtonPin1 = LOW;
int stateButtonPin2 = LOW;

// delays:
int delayTime = 10000;
int focusDelay = 100;
int flashDelay = 100;
int shutterDelay = 100;

// edges:
#define RISINGEDGE 1
#define FALLINGEDGE 2

// sensor thresholds:
int piezoTheshold = 0;
int laserTheshold = 1000;  //TODO: change this value when the laser is connected

// sensor pins:
int piezoPin = A2;
int laserPin = A1;

// sensor values:
int piezo = 0;
int laser = 0;

// sensor delays (to avoid taking multiple pictures)
int piezoDelay = 100;
int laserDelay = 10;

boolean started = false;

void setup()
{
  Serial.begin(115200);
  pinMode(flashPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  pinMode(focusPin, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  laser = analogRead(laserPin);
  Serial.print("Startvalue laser: ");
  Serial.print(laser);
  //laserTheshold = laser - 200;
  Serial.print("  --> Threshold: ");
  Serial.println(laserTheshold);  
}

void loop()
{
  if(risingEdgePin2() == RISINGEDGE)
  {
     started = true;
     Serial.println("start");
  }
  
  if (started){
    readSensors();
    //printSensors();
    doActions();
    //manualMode();
    //delay(1000);
  }
}

int readSensors()
{
  //piezo = analogRead(piezoPin);
  laser = analogRead(laserPin);
}

int printSensors()
{
  Serial.print("Laser: ");
  Serial.print(laser);
  Serial.print(" - Piezo: ");
  Serial.println(piezo);
}

void doActions()
{
  if (piezo < piezoTheshold)
  {
    shutter();
    delay(piezoDelay);
  }
  if (laser < laserTheshold)
  {
    //shutter();
    Serial.println("Foto");
    delay(laserDelay);
  }
}

void takePicture()
{
  focus();
  shutter();
}

void shutter()
{
  digitalWrite(shutterPin, HIGH);
  //Serial.println("Shutter");
  delay(shutterDelay);                            // wait a short time for the shutter to complete
  digitalWrite(shutterPin, LOW);
}

void focus()
{
  digitalWrite(focusPin, HIGH);
  Serial.println("Focus");
  delay(focusDelay);                              // wait a short time for the focus to complete
  digitalWrite(focusPin, LOW);
}

void flash()
{
  digitalWrite(flashPin, HIGH);
  Serial.println("Flash");
  delay(flashDelay);                              // wait a short time for the flash to complete
  digitalWrite(flashPin, LOW);
}

void manualMode()
{
  if(risingEdgePin1() == RISINGEDGE)
  {
    Serial.println("Rising edge button 1");
    takePicture();

  }
  if(risingEdgePin2() == RISINGEDGE)
  {
    Serial.println("Rising edge button 2");
    takePicture();
  }
}

int risingEdgePin1()
{
  int currentReading = digitalRead(buttonPin1);
  delay(10);                                      //debounce
  if(currentReading && !stateButtonPin1)
  {
    stateButtonPin1 = HIGH;
    return(RISINGEDGE);
  }
  else if(!currentReading)
  {
    stateButtonPin1 = LOW;
  }
  return(0);
}

int risingEdgePin2()
{
  int currentReading = digitalRead(buttonPin2);
  delay(10);                                      //debounce
  if(currentReading && !stateButtonPin2)
  {
    stateButtonPin2 = HIGH;
    return(RISINGEDGE);
  }
  else if(!currentReading)
  {
    stateButtonPin2 = LOW;
  }
  return(0);
}
