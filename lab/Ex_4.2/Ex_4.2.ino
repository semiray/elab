/*

 For circuit i used:
 * 8-ohm speaker on digital pin 9
 * photoresistor on analog 0 to 5V
 * 5K resistor on analog 0 to ground
 */


void setup() {
  Serial.begin(9600);
}

void loop() {
  // for reading the sensor:
  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);
  int thisPitch = map(sensorReading, 10, 800, 120, 1500);

  // play the pitch:
  tone(9, thisPitch, 10);
  delay(1);       
}
