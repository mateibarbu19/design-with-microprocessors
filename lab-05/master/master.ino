#include "SPI.h"

void setup() {
  SPCR |= (1 << MSTR); // Set master mode.
  SPCR |= (1 << SPR0); // Set prescaler 16.
  SPCR |= (1 << SPE); // Enable SPI.

  Serial.begin(9600);
}

void sendSPI() {
  SPDR = 123; // Start transmission.

  digitalWrite(10, LOW);
  
  while(!(SPSR & (1 << SPIF))); // Wait for transmission to be over.

  Serial.print("One transmission done!\n");
}

void loop() {
  while (true) {
    sendSPI();
    delay(100);
  }
}
