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
  configure_pins();
}

void loop()
{
  manualMode();
}
