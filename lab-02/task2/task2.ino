#include "usart.h"
#define BUTTON PD2

const char pressed_msg[] = "The button was pressed\n";
const char not_pressed_msg[] = "The button was not pressed\n";

void setup()
{
  USART0_init();
  USART0_print("Hello\n");
  DDRD &= ~(1 << BUTTON); // set it as as input
  PORTD |= (1 << BUTTON); // activate the pull-up
}

void loop()
{
  if ((PIND & (1 << BUTTON)) == 0) {
    USART0_print(pressed_msg);
  } else {
    USART0_print(not_pressed_msg);
  }
  delay(1000);
}
