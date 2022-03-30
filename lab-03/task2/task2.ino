#include <time.h>
#include <stdlib.h>
int led1 = 9;
int led2 = 10;
int led3 = 11;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  srand(time(NULL));
}

void loop() {
  int val1 = 1.f * rand() / RAND_MAX * 255;
  int val2 = 1.f * rand() / RAND_MAX * 255;
  int val3 = 1.f * rand() / RAND_MAX * 255;
  analogWrite(led1, val1);
  analogWrite(led2, val2);
  analogWrite(led3, val3);
  delay(150);
}
