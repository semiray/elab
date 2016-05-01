
/*In this project i tried to measure the temperature and humidity of the room using temp-humidity sensor
  For the project i used: 
     * 16x2 LCD
     * DHT11 sensor
     * Potantiometer
     * Arduino
     * Wires
I also added the picture of the project inside the main directory.

*/

#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7

void setup(){
  lcd.begin(16, 2);
 
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp.(C)  = ");
  lcd.print(DHT.temperature);
  lcd.setCursor(0,1);
  lcd.print("Humidity% = ");
  lcd.print(DHT.humidity);
  delay(1000);
}


