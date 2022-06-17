int lastInterruptTime = 0;
int ledState = HIGH;

int BUTTON = 3;
int LED = 11;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  cli();

  EICRA = 0;
  EICRA |= (1 << ISC11);    // set interrupt on falling edge
  EIMSK = 0;
  EIMSK |= (1 << INT1);     // enable INT1 interrupt

  sei();
}

ISR(INT1_vect) {
  if (millis() - lastInterruptTime > 400) {
    lastInterruptTime = millis();

    if (ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }
  }
}

void loop() {
  digitalWrite(LED, ledState);
}
