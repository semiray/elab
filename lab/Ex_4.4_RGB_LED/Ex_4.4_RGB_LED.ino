int redPin=11;  //set red LED pin to 11
int greenPin=10; //set green LED pin to 10
int bluePin=6; //set blue LED pin to 6
int brightness=500; //Set brightness to 500

void setup() {
 
Serial.begin(9600); //Turn on Serial port
pinMode(redPin, OUTPUT); //Set redPin to be an output
pinMode(greenPin, OUTPUT); //Set greenPin to be an output
pinMode(bluePin, OUTPUT); //Set bluePin to be an output
 
}
 
void loop() {
   
  analogWrite(redPin, brightness); 
  delay(500);
  analogWrite(greenPin, brightness); 
  delay(500);
  analogWrite(bluePin, brightness); //write 500 (brightness) for blue pin
  delay(500);

  analogWrite(redPin, 0); // red pin off
  delay(500);
  analogWrite(greenPin,0); //green pin off
  delay(500);
  analogWrite(bluePin, 0); //write 500 (brightness) for blue pin
  delay(500);
}
