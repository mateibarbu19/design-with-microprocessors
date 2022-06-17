#define LED PB5
#define BUTTON PD2

void setup() {
  DDRB |= (1 << LED); // pin 13 = output
  DDRD &= ~(1 << BUTTON); // pin 2 = input
  PORTD |= (1 << BUTTON); // activeaza pull-up la pinul 2
}
 
void loop() {
  if (PIND & (1 << BUTTON) == 0) {
      PORTB |= (1 << LED); // Porneste led-ul
    } else {
      PORTB &= ~(1 << LED); // Opreste led-ul
    }
}
