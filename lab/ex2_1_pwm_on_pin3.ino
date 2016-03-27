
const int analogOutPin = 3;  // Analog input pin that the potentiometer is attached to
const int pws[] = {0, 64, 192, 255};

// results:
// 0 = 0
// 64 = 500us
// 192 = 1500us
// 255 = constant current

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  while(false) {  
    for (int i=0; i<256; i++) {
      // change the analog out value:
      analogWrite(analogOutPin, i);           
      Serial.print("value=");
      Serial.println(i);
      delay(200);    
    }
  }
  for (int i=0; i<4; i++) {
    analogWrite(analogOutPin, pws[i]);
    Serial.print("value=");
    Serial.println(pws[i]);
    delay(5000);
  }
}
