
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

