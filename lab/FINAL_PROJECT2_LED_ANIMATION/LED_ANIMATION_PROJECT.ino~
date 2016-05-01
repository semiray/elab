/*This is the second final project, in this project i used different color leds
and tried to the animation demonstration.

  
int LedCount = 8;
int pwmLEDPins[8] = {3, 4, 5, 6, 7, 8, 9, 10};
  
  
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LedCount; i++) {
    pinMode(pwmLEDPins[i], OUTPUT);
  }
}
  
void loop() {
  stateOne();
  stateTwo();
  stateThree();
  stateFour();
  stateFive();
  stateSix();
  stateSeven();
  turnAll(LOW);
  delay(1500);
}
  
void stateOne() {
  int stateOne[8] = {0, 0, 0, 0, 0, 0, 0, 0  };
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < LedCount; i++) {
      stateOne[i] = ~stateOne[i];
      digitalWrite(pwmLEDPins[i], stateOne[i]);
      delay(60);
    }
  }
}
  
void stateTwo() {
  int stateTwo[8] = {0, 1, 0, 1, 0, 1, 0, 1  };
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < LedCount; i++) {
      stateTwo[i] = ~stateTwo[i];
      digitalWrite(pwmLEDPins[i], stateTwo[i]);
      delay(100);
    }
  }
}
  
void stateThree() {
  int stateThree[8] = {0, 0, 0, 0, 0, 0,  0 ,0  };
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < LedCount; i++) {
      stateThree[i] = ~stateThree[i];
      digitalWrite(pwmLEDPins[i], stateThree[i]);
      delay(100);
    }
    for (int i = (LedCount-1); i >= 0; i--) {
      stateThree[i] = ~stateThree[i];
      digitalWrite(pwmLEDPins[i], stateThree[i]);
      delay(50);
    }
  }
}
  
void stateFour() {
  int stateFour[8] = {0, 0, 0, 0, 1, 1, 1, 1 };
  for (int k = 0; k < 7; k++) {
    for (int j = 0; j < 240; j++) {
      for (int i = 0; i < LedCount; i++) {
        analogWrite(pwmLEDPins[i], j);
        stateFour[i] = j;
      }
      delay(2);
    }
  
    for (int j = 192; j >= 0; j--) {
      for (int i = 0; i < LedCount; i++) {
        analogWrite(pwmLEDPins[i], j);
        stateFour[i] = j;
      }
      delay(4);
    }
  }
}
  
void stateFive() {
  int stateFive[8] = {1, 1, 1, 1, 0, 0, 0, 0  };
  for (int j = 0; j < 50; j++) {
    for (int i = 0; i < LedCount; i++) {
      stateFive[i] = !stateFive[i];
      digitalWrite(pwmLEDPins[i], stateFive[i]);
    }
    delay((1500/(j+1)));
  }
}



void stateSix() {
  int stateSix[8] = {1, 1, 1, 1, 0, 0, 0, 0  };
  for (int j = 0; j < 50; j++) {
    for (int i = 0; i < LedCount; i++) {
      stateSix[i] = !stateSix[i];
      digitalWrite(pwmLEDPins[i], stateSix[i]);
    }
    delay((1500/(j+1)));
  }
}



void stateSeven() {
  int stateSeven[8] = {1, 1, 1, 1, 0, 0, 0, 0  };
  for (int j = 0; j < 50; j++) {
    for (int i = 0; i < LedCount; i++) {
      stateSeven[i] = !stateSeven[i];
      digitalWrite(pwmLEDPins[i], stateSeven[i]);
    }
    delay((1500/(j+1)));
  }
}

  
void turnAll(int value) {
  for (int i = 0; i < LedCount; i++) {
    digitalWrite(pwmLEDPins[i], value);
  }
}

