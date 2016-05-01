int x; // variable of x axis
int y; // variable of y axis
int z; // variable ofz axis
void setup()
{ 
   Serial.begin(9600); //  sets data rate to 9600 bps
}
void loop()
{
  x = analogRead(0); // read A0 input pin
  y = analogRead(1); // read A1 input pin
  z = analogRead(2); // read A2 input pin
  Serial.print("X = "); // print x adc value
  Serial.println(x);
  Serial.print("Y = "); // print y adc value
  Serial.println(y);
  Serial.print("Z = "); // print z adc value
  Serial.println(z);
  delay(3000);
}
