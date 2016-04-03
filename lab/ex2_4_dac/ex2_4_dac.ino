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
  measureMaxFreq(10000);
 
}

void measureMaxFreq(int cycle) {
  float start = millis();
  int i = 0;
  while (i < cycle) {
    dacWrite(0);
    dacWrite(4000);
    i++;
  }

  float elapsed = millis() - start;
  Serial.print("one cycle finished in (ms) ");
  Serial.println( elapsed );
  
  Serial.print("Number of operations per millisecond` ");
  Serial.println( (cycle*2) / elapsed );
  // this will print:
  // one cycle finished in (ms) 7157.00
  // Number of operations per millisecond 2.79

  // That would mean spead of 2.79kHZ.
  // However, the oscilloscope shows ~700us per full cycle
  // which is ~1.4kHz (at the output). Also, the input
  // is the same speed (it seems). So, probably if Arduino
  // could write faster, the DAC would output faster (???)
}

void rampUp(int d) {
 // steady ramp up of voltage
  // for some reason I can't get more than 4V
  // Arduino is sending 5V, but DAC will output
  // max of 4V
  for (int i=0; i<4096; i=i+1) {
    dacWrite(i);
    delay(d);
  }  
}

/**
 * 2.6 wanted to have a function which receives a word
 * but I prefer to pass just the values (and have static
 * config). This is what I would do to handle 16bits
 */
void setDac( word w) {
  byte conf = (w >> 12) & B1111; // take the first 4 bits (shift 12 right and bitmask)
  int value = w & 0000111111111111; // remove the config (word is the same size as int)
  //writeConfig(conf);
  dacWrite(value);
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
