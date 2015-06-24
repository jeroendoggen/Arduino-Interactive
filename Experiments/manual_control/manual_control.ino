// Arduino Interactive: Optocoupler Example
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

// TODO: change the pin numbers where needed -> this code was tested with Fotomind 2.0 (not Fotomind Mini)

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

// edges
#define RISINGEDGE 1
#define FALLINGEDGE 2

void setup()
{
  Serial.begin(9600);
  pinMode(flashPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  pinMode(focusPin, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop()
{
  manualMode();
}

void takePicture()
{
  focus();
  shutter();
}

void shutter()
{
  digitalWrite(shutterPin, HIGH);
  Serial.println("Shutter");
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
    focus();
  }
  if(risingEdgePin2() == RISINGEDGE)
  {
    Serial.println("Rising edge button 2");
    shutter();
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
