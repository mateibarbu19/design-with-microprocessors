void setup() {
  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= (1 << WGM12); // CTC mode
  OCR1A = 15525;
  TCCR1B |= (1 << CS12);    // 256 prescaler
}

ISR(TIMER1_COMPA_vect) {
  // cod întrerupere 
}

void loop() {
  ;
}
