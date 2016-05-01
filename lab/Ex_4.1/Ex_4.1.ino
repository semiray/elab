/*

Info: The servo has a cable attached to it with three wires.These are:

  Connect the RED wire (power) to 5 Volts (5V)
  Connect the WHITE wire (signal) to digital pin 9
  Connect the BLACK wire (ground) to ground (GND)

*/

#include <Servo.h>  // servo library
Servo servo_pin;  // servo control object


void setup()
{
  
  servo_pin.attach(9); // attached the servo1 object to digital pin 9
}


void loop()
{
  int position;

  // To control a servo, we can give it the angle that we'd like it to turn to.

  servo_pin.write(90);    // give command to servo to go to 90 degrees

  delay(1500);         // Pause to get it time to move

  servo_pin.write(180);   // give command to servo to go to 180 degrees

  delay(1500);         // Pause to get it time to move

  servo_pin.write(0);     // give command  to servo to go to 0 degrees

  delay(1500);         // Pause to get it time to move


  // We Command servo to go to 180 degrees, stepping by two degrees

  for(position = 0; position < 180; position += 2)
  {
    servo_pin.write(position);  // Move to next position
    delay(10);               //for a while it will pause to akkow it to move
  }

  //  we command servo to go to 0 degrees, stepping by one degree

  for(position = 180; position >= 0; position -= 1)
  {                                
    servo_pin.write(position);  // Move to next position
    delay(10);               // for a while pause to allow it to move
  }
}

