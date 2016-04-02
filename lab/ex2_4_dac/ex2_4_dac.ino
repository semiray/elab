int pinCSn = 10; // 2 on DAC - to initiate communication
int pinSDI = 11; // 4 on DAC - write data
int pinSCK = 13; // 3 on DAC - clock

/**
 * experiment: 2 Vout = 1660
 *             4.02V = >3600 was highest output (because the current is drawn from Arduino?)
 */

void setup() {
  pinMode( pinCSn, OUTPUT);
  pinMode( pinSCK, OUTPUT);
  pinMode( pinSDI, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  // steady ramp up of voltage
  for (int i=0; i<4095; i=i+100) {
    dacWrite(i);
//    Serial.println(i);
    delay(100);
  }
}

/**
 * Write into the MSP4921. The max value is 4095
 * because the device receives 4bits in header, 
 * and 12 bits as a value (2^12)-1 - the header is
 * static (so here we are just writing values)
 */
void dacWrite(int value) {
  digitalWrite( pinCSn, LOW); // initiate communication
  sendHeader(); // write first 4 bits
  for (int i=11; i>=0; i--) {
    sdiWrite((value&(1<<i))>>i);
  }
  digitalWrite( pinCSn, HIGH); // close communication
}

/*
 * The MSP4921 receives first 4 bits (configuration)
 */
void sendHeader() {
  sdiWrite(LOW);  // 0=write to DAC, 1=ignore command
  sdiWrite(LOW); // 0=unbuffered, 1=buffered
  sdiWrite(HIGH); // 0=2x gain, 1=1x gain (Vref)
  sdiWrite(HIGH); // 0=shutdown device, 1=active mode
}

/* 
Writes a bit into the DAC
*/
void sdiWrite(int v) {
  digitalWrite(pinSDI, v);
  digitalWrite(pinSCK, HIGH); // have to send a clock signal after writing to the SDI
  digitalWrite(pinSCK, LOW);  
}
