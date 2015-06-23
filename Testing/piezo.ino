// Arduino Interactive: Piezo Example
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

// These constants probably won't change:
const int ledPin = 6;                             // led connected to digital pin 6
const int knockSensor = A0;                       // the piezo is connected to analog pin 0

// Change this threshold value as needed
const int threshold = 100;                        // threshold value to decide when the detected sound is a knock or not

// These variables will change:
int sensorReading = 0;                            // variable to store the value read from the sensor pin
int ledState = LOW;                               // variable used to store the last LED status, to toggle the light

void setup()
{
   pinMode(ledPin, OUTPUT);                      // declare the ledPin as as OUTPUT
   Serial.begin(9600);                           // use the serial port
}

void loop()
{
  sensorReading = analogRead(knockSensor);        // read the sensor and store it in the variable sensorReading:
  Serial.println(sensorReading);                  // print out the sensor value (just for debugging)

  if (sensorReading <= threshold)                 // if the sensor reading is greater than the threshold:
  {
    ledState = !ledState;                         // toggle the status of the ledPin:
    digitalWrite(ledPin, ledState);               // update the LED pin itself:
    Serial.println("Knock!");                     // send the string "Knock!" back to the computer
  }
  delay(100);                                    // delay to avoid overloading the serial port buffer
}
