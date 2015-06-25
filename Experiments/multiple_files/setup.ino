void configure_pins()
{
  
  pinMode(flashPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  pinMode(focusPin, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

