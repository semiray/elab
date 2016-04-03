#include <TimerOne.h>
#include <SPI.h>

int pinCSn = 10; // 2 on DAC - to initiate communication
int pinSDI = 11; // 4 on DAC - write data
int pinSCK = 13; // 3 on DAC - clock

/**
When I use the full scale of the DAC 0-4095, the wave has top wider than the bottom.
That's because setDac(4095) only goes up to 4V. I'll have to try with the external
power source connected (in the lab). 
**/

float freq = 500.0;
float amplitude = 1.0; // amplitude in V
float dacRange = 0.0; // will be computed based on the amplitude
volatile int dac = 0;
const float pi2 = 3.1415927 * 2.0;
  
void timerFunc() {
  static float a;      // sin angle in radians
  static float da = pi2/8;  // delta-a (increment value)
  unsigned int d;      // DAC value 0-4095 (12 bits)

  d = dacRange + (dacRange-1.0) * sin(a);
  setDac( d);
  a += da;
  if( a > pi2) a = a - pi2;

}

void setup() {
  // 4095 would be 5V (but since we are DC, half of that is max: 2048)
  float newAmpl = amplitude / 2.5;
  dacRange = newAmpl * 2048;
  
  Timer1.initialize( 1000 / freq * 1000  );    // timer interrupt
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




