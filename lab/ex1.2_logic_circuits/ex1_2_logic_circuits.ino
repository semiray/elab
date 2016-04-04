

const int ledStart = 8;
const int buttonStart = 2;
const int numButtons = 2;

void setup() {
  for (int i=0; i< numButtons; i++) {
    pinMode(ledStart + i, OUTPUT);
    pinMode(buttonStart + i, INPUT_PULLUP);  
  }
}

void loop() {
  int states[numButtons];
  for (int i=0; i < numButtons; i++) {
    states[i] = digitalRead(buttonStart + i);
  }
  
  if (states[0] & states[1]) { // by default, the signal is on (so this will execute when none button is pressed)
    digitalWrite(ledStart, LOW); 
  }
  else if(states[0] | states[1]) { // if one of them is pressed
    digitalWrite(ledStart, HIGH);
  }
  else {
    digitalWrite(ledStart, HIGH); // both button pressed
  }
  
}

