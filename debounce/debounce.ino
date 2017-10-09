const int buttonPin = 2;
unsigned long lastInterruptTime = 0;  // the last time the output pin was toggled
unsigned long now = 0;

//ISR
void buttonPressed() {
  now = millis();
  if(now - lastInterruptTime > 200){ // If it's been at least 200 ms since the button was last pressed.
    Serial.println("Interrupt");
  }
  lastInterruptTime = now;
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  // Interrupts can happen on "edges" of signals.  
  // Three edge types are supported: CHANGE, RISING, and FALLING 
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING);
  Serial.begin(9600);
}



void loop() {
  for(int i=0;i<100;i++) {
    Serial.println(i);
    delay(1000);
  }
}
