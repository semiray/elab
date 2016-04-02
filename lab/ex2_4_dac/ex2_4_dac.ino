int pinSDI = 11;
int pinSCK = 13;
int pinCSn = 10;			// pin number for nCS

void setup() {				// setup function runs once
  pinMode( pinCSn, OUTPUT);	// define nCS as an output
  digitalWrite(pinCSn, HIGH);
  digitalWrite(pinSCK, LOW);
}

int data[16] = {0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0};

void loop() {
  digitalWrite( pinCSn, 0);	// set nCS to 0 (LOW)
  
  for (int i=0; i < 16; i++) {
    digitalWrite(pinSCK, HIGH);
    digitalWrite(pinSDI, data[i]);      
    digitalWrite(pinSCK, LOW);
  }
  
  digitalWrite( pinCSn, 1);	// set nCS to 1 (HIGH)
}

