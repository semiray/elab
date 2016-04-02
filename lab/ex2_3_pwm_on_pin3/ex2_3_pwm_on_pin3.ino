
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

int d = 150;                    // half-cycle delay in ms

void loop() {
	analogWrite( 3, 0);      // set PWM to minimum
	delay( d);
	analogWrite( 3, 255);    // set PWM to maximum
	delay( d);
}

// when d =1 frequency is 490 Hz
//when d=2 frequency is 247Hz
//when d=3 frequency is 165Hz
//when d =4  frequency is 125 and voltage is 2V

// when d=150, the input (5v) drops to ~1.5V on output
