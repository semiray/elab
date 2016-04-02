
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

int d = 4;                    // half-cycle delay in ms

void loop() {
	analogWrite( 3, 0);      // set PWM to minimum
	delay( d);
	analogWrite( 3, 255);    // set PWM to maximum
	delay( d);
}

