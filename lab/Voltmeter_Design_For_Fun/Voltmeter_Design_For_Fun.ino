#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 10, 3, 4, 5, 6);

float input_voltage = 0.0;
float temp=0.0;


void setup()
{
   Serial.begin(9600);     
   lcd.begin(16, 2);      
   lcd.print("VOLTMETER");
}
void loop()
{
   
   int analog_value = analogRead(A0);
   input_voltage = (analog_value * 5.0) / 1024.0; 

   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    Serial.print("v= ");
    Serial.println(input_voltage);
    lcd.setCursor(0, 1);
    lcd.print("Voltage= ");
    lcd.print(input_voltage);
    delay(300);
}
