
const int analogOutPin = 3;  // Analog input pin that the potentiometer is attached to
const int pws[] = {0, 64, 192, 255};

// results:
// 0 = 0, 0V
// 64 = 500us, 1.2V
// 192 = 1500us, 2.3V
// 255 = 2ms, 4.9V

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {

    for (int i=0; i<4; i++) {
	analogWrite(analogOutPin, pws[i]);
	// this results in a relatively very steady
        // current close to 2V
        // a yellow LED flickers, probably because we 
        // step over the LED's voltage threshold (just slighly)
        // oscilloscope shows steady line after the capacitor
        delay(2000);
    }
}
