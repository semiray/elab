#include <LiquidCrystal.h> //include library

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

 
int Pin_Led = 13;                    // LED connected to digital pin 13
int Pin_Button = 2;                  // button on pin 2
 
 
int value = LOW;                    // previous value of the LED
int buttonState;                   
int lastButtonState;                
int blinking;                       
int frameRate = 100;                // the frame rate at which the stopwatch runs 
long timeslot = (1000/frameRate);   // blink interval
long previousMillis = 0;            // variable to store last time LED was updated
long startTime ;                    // start time for stopwatch
long passedTime ;                  // passed time for stopwatch
int fractional;                     // variable used to store fractional part of Frames
int fractionalSecs;                
int fractionalMins;                 
int passedFrames;                  // passed frames for stopwatch
int passedSeconds;                 
int passedMinutes;                 
char buf[10];                       
 
 
void setup()
{
  lcd.begin(16, 2);                
  pinMode(Pin_Led, OUTPUT);         
  pinMode(Pin_Button, INPUT);      
  digitalWrite(Pin_Button, HIGH);   
  lcd.setCursor(0,0);
  lcd.print("Digital Clock is");
  lcd.setCursor(5,1);
  lcd.print("READY");
}
 
 
void loop(){
 
 
  digitalWrite(Pin_Led, LOW);            
 
 
  buttonState = digitalRead(Pin_Button); 
 
  
   if (buttonState == LOW && lastButtonState == HIGH  &&  blinking == false){
      startTime = millis();                              
      blinking = true;                                  
      delay(10);                                        
      lastButtonState = buttonState;                    // store buttonState in lastButtonState, to compare next time
   }
 
 
   else if (buttonState == LOW && lastButtonState == HIGH && blinking == true){
   blinking = false;                                   
   lastButtonState = buttonState;                    
 
         
   passedTime =   millis() - startTime;                // store passed time
   passedMinutes = (passedTime / 60000L);
   passedSeconds = (passedTime / 1000L);              // divide by 1000 to convert to seconds
   passedFrames = (passedTime / timeslot);            // divide by 100 to convert to 1/100 of a second
   fractional = (int)(passedFrames % frameRate);      
   fractionalSecs = (int)(passedSeconds % 60L);        
   fractionalMins = (int)(passedMinutes % 60L);        
   lcd.clear();                                        
 
 
if (fractionalMins < 10){                           
      lcd.print("0");                               
      }
 
 
    lcd.print(itoa(fractionalMins, buf, 10));      
      lcd.print(":");                                 
 
 
if (fractionalSecs < 10){                            
      lcd.print("0");                                 
      }
 
 
lcd.print(itoa(fractionalSecs, buf, 10));         
   lcd.print(":");                                    
 
 
if (fractional < 10){                               
      lcd.print("0");                                
      }    
 
 
lcd.print(itoa(fractional, buf, 10));              
   }
 
 
else{
      lastButtonState = buttonState;                 
   }
 

 
if ( (millis() - previousMillis > timeslot) ) {
 
 
    if (blinking == true){
       previousMillis = millis();                
 
 
       digitalWrite(Pin_Led, HIGH);                   
 
 
         passedTime =   millis() - startTime;         
         passedMinutes = (passedTime / 60000L);      
         passedSeconds = (passedTime / 1000L);       
         passedFrames = (passedTime / timeslot);     
         fractional = (int)(passedFrames % frameRate);
         fractionalSecs = (int)(passedSeconds % 60L); 
         fractionalMins = (int)(passedMinutes % 60L); 
         lcd.clear();                                  
 
 
       if (fractionalMins < 10){                     
         lcd.print("0");                            
         }
 
 
       lcd.print(itoa(fractionalMins, buf, 10));   
         lcd.print(":");                             
 
 
       if (fractionalSecs < 10){                     
         lcd.print("0");                            
         }
 
 
       lcd.print(itoa(fractionalSecs, buf, 10));   
         lcd.print(":");                             
 
 
       if (fractional < 10){                         
         lcd.print("0");                             
         }
          lcd.print(itoa((fractional), buf, 10));  
         }
 
 
    else{
          digitalWrite(Pin_Led, LOW);                 
          
          }
}
 
 
}

