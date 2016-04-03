#include <TimerOne.h>
#include <SPI.h>

int pinCSn = 10; // 2 on DAC - to initiate communication
int pinSDI = 11; // 4 on DAC - write data
int pinSCK = 13; // 3 on DAC - clock

/**
Make it 500Hz precisely.
**/

volatile int dac = 0;
void timerFunc() {
  setDac( dac);			// update the DAC output
  dac ^= 0xfff;  		// XOR (toggle) all 12 bits
}

void setup() {
  Timer1.initialize( 1000 );    // timer interrupt every 1000us (500Hz)
  Timer1.attachInterrupt( timerFunc);  // call every interrupt

  SPI.begin();
  SPI.setBitOrder( MSBFIRST);
  Serial.begin(9600);
}


void loop() {

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




