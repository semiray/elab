/* 
*/
 
#include <IRremote.h>
 
int RECV_PIN = 3; // the pin where we connected the output pin
int led1 = 8;
int led2 = 9;
int led3 = 10;
int ledState[] = {0,0,0,0};
/* the initial state of LEDs is OFF (zero) */

#define code1  63495 // code received from button A
#define code2  30855 // code received from button B
#define code3  22695 // code received from button C
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);   
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
 
void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1:
         if(ledState[1] == 1) {        // if 1st led is on
            digitalWrite(led1, LOW);   // turn the 1st led off, when button is pressed
            ledState[1] = 0;           // and set its state as 0 (OFF)
         } else {                      // else if 1st led is off
             digitalWrite(led1, HIGH); // turn 1st led  on when the button is pressed
             ledState[1] = 1;          // and set its state as 1(ON)
         }
          break; 
       case code2:
         if(ledState[2] == 1) {         // if 2nd led is on
            digitalWrite(led2, LOW);    // turn the 2nd led off, when button is pressed
            ledState[2] = 0;            // and set its state as 0 (OFF)
         } else {                       // else if 2nd led is off
             digitalWrite(led2, HIGH);  // turn 2nd led  on when the button is pressed
             ledState[2] = 1;           // and set its state as 1(ON)
         }
          break;
       case code3:
         if(ledState[3] == 1) {         // if 3th led is on
            digitalWrite(led3, LOW);    // turn the 3th led off, when button is pressed
            ledState[3] = 0;            // and set its state as 0 (OFF)
         } else {                       // else if 3th led is off
             digitalWrite(led3, HIGH);  // turn 3th led  on when the button is pressed
             ledState[3] = 1;           // and set its state as 1(ON)
         }
          break;          
    }
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
}
