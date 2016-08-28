int pb1 = 2, pb2 = 3, pb3 = 4, pbst1, pbst2, pbst3, led1 = 5, led2 = 6;
unsigned long prevMillis = 0;
const long interval = 75;
int ledState = HIGH;
int pressed = LOW;




void setup() {

  for (int i = 2; i < 5; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  for (int i = 5; i < 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Pseudo Code
  stateReader(&pbst1, pb1);
  stateReader(&pbst2, pb2);
  stateReader(&pbst3, pb3);

  if (pbst1 == pressed && pbst2 == pressed && pbst3 == pressed) {
    turnedOff();
  }
  else if (pbst1 == pressed && pbst2 == pressed) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if (pbst2 == pressed && pbst3 == pressed) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }
  else if (pbst1 == pressed && pbst3 == pressed) {
    // Create function for led 1 and 2 to blink fast
    blinkFast();
  }
  
  else if (pbst1 == pressed || pbst2 == pressed || pbst3 == pressed) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else {
    turnedOff();
  }
}

void stateReader(int *i, int j) {
  *i = digitalRead(j);
}
void turnedOff(void) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}
void blinkFast() {
  unsigned long currMillis = millis();

  if (currMillis - prevMillis >= interval) {
    prevMillis = currMillis;
    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
    ledState = !ledState;
  }
}
