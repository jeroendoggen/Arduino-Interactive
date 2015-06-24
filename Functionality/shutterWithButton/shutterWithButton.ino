// Arduino Interactive: stop-motion example
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

int delayTime = 100;  // 10 seconds
int ausl = 11;
int shutter = 9;
int buttonState = 0;
int led = 6;
int focus = 10;


void setup()
{
    pinMode(ausl, INPUT);
    pinMode(shutter, OUTPUT);
    pinMode(focus, OUTPUT);
    pinMode(led, OUTPUT);  //TODO                                      // configure the input pins
     //TODO                                      // configure the output pins
     Serial.begin(9600);                         // use the serial port
}

void loop()
{
  takePicture();
  delay(delayTime);                              // delay between pictures
}

void takePicture()
{
buttonState = digitalRead(ausl);

if(buttonState == HIGH)

  {digitalWrite(shutter, HIGH);
  digitalWrite(focus, HIGH);
  Serial.println("Shutter");
  digitalWrite(led, HIGH);
  
  }
  else{
    digitalWrite(shutter, LOW);
    digitalWrite(focus, LOW);
    digitalWrite(led, LOW);
    
  }

{
  
  
}

// do stuff here
}
