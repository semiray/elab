

const int ledStart = 8;
const int buttonStart = 2;
const int numButtons = 4;

void setup() {
  for (int i=0; i< numButtons; i++) {
    pinMode(ledStart + i, OUTPUT);
    pinMode(buttonStart + i, INPUT_PULLUP);  
  }
}

void loop() {
  
  for (int i=0; i < numButtons; i++) {
    int buttonState = digitalRead(buttonStart + i);
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
      // turn LED on:
      digitalWrite(ledStart+i, HIGH);
    } else {
      // turn LED off:
      digitalWrite(ledStart+i, LOW);
      
    }
  }
}

