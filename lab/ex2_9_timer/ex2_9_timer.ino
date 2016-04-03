#include <TimerOne.h>
#include <SPI.h>

int pinCSn = 10; // 2 on DAC - to initiate communication
int pinSDI = 11; // 4 on DAC - write data
int pinSCK = 13; // 3 on DAC - clock

/**
This will trigger signal every 250us (2kHz, very stable)
The max we were able to reach was 18.6kHz (16us interrupt)
Which is actually lower than SPI, is that right?
**/

volatile int dac = 0;
void timerFunc() {
  setDac( dac);			// update the DAC output
  dac ^= 0xfff;  		// XOR (toggle) all 12 bits
}

void setup() {
  Timer1.initialize( 16 );    // timer interrupt every 250us
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
  SPI.transfer(high);
  SPI.transfer(lowByte(w));
  digitalWrite( pinCSn, HIGH); // close communication
}




