// Arduino Interactive: Photo resistor Example
// Copyright 2015 Jeroen Doggen, Christian Munk, Tom Peeters

const int sensorMin = 0;                          // sensor minimum, discovered through experiment
const int sensorMax = 600;                        // sensor maximum, discovered through experiment

void setup()
{
  Serial.begin(9600);                             // initialize serial communication:
}

void loop()
{
  int sensorReading = analogRead(A0);             // read the sensor:
                                                  // map the sensor range to a range of four options:
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range)                                  // do something different depending on the range value:
  {
    case 0:                                       // your hand is on the sensor
      Serial.println("dark");
      break;
    case 1:                                       // your hand is close to the sensor
      Serial.println("dim");
      break;
    case 2:                                       // your hand is a few inches from the sensor
      Serial.println("medium");
      break;
    case 3:                                       // your hand is nowhere near the sensor
      Serial.println("bright");
      break;
  }
  delay(1);                                       // delay in between reads for stability
}
