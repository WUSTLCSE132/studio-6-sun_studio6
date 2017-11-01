const byte buttonPin = 2;
const byte ledPin = 13;
unsigned long lastInterruptTime = 0;  // the last time the output pin was toggled
unsigned long now = 0;
volatile byte state = LOW;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  // Three edge types are supported: CHANGE, RISING, and FALLING 
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, state);
}

//ISR
void buttonPressed() {
  now = millis();
  if(now - lastInterruptTime > 200){ // If it's been at least 200 ms since the button was last pressed.
    state = !state;
  }
  lastInterruptTime = now;
}
