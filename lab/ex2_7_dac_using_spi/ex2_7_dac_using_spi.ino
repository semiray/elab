#include <SPI.h>

int pinCSn = 10; // 2 on DAC - to initiate communication
int pinSDI = 11; // 4 on DAC - write data
int pinSCK = 13; // 3 on DAC - clock

/**
The lab book says we should get 30kHz, but I'm seeing ~24kHz
One cycle each 40us

But indeed, I'm seeing 2 signals per 5ns (and sometimes 5ns nothing)

**/

void setup() {
  SPI.begin();
  SPI.setBitOrder( MSBFIRST);
  Serial.begin(9600);
}


void loop() {
  //rampUp(5);
  while(true) {
    setDac(0);
    setDac(4095);
  }
}


void rampUp(int d) {
  for (int i=0; i<4096; i=i+10) {
    setDac(i);
    delay(d);
  }  
}


void setDac( word w) {
  digitalWrite( pinCSn, LOW); // initiate communication
  byte high = highByte(w);
  bitClear(high, 7); // active mode
  bitClear(high, 6); // unbuffered
  bitSet(high, 5); // 1x gain
  bitSet(high, 4); // 
  //Serial.println(w);
  //Serial.println(high, BIN);
  //Serial.println(lowByte(w));
  //Serial.println("---");
  SPI.transfer(high);
  SPI.transfer(lowByte(w));
  digitalWrite( pinCSn, HIGH); // close communication
}




