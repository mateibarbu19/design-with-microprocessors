unsigned const int a = 11;
unsigned const int b = 10;
unsigned const int c = 7;
unsigned const int d = 8;
unsigned const int e = 9;
unsigned const int f = 12;
unsigned const int g = 13;
unsigned const int dp = 6;
int ledState = LOW;           // Starea curenta a ledului
int buttonState;              // valoarea starii butonului
int lastButtonState = HIGH;   // valoarea anterioara a starii butonului
int lastInterruptTime = 0;
unsigned const int Button = 3;
unsigned const int LED = 5;

void setup() {
  pinMode(Button, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  turnOff();
  
  cli();

  EICRA |= (1 << ISC11);    // set interrupt on falling edge
  EIMSK |= (1 << INT1);     // enable INT1 interrupt

  sei();
}

void turnOff()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void displayDigit(int digit)
{
  if (digit != 0 && digit != 1 && digit != 7)
    digitalWrite(g, LOW);

  //Conditions for displaying segment a
  if (digit != 1 && digit != 4)
    digitalWrite(a, LOW);

  //Conditions for displaying segment b
  if (digit != 5 && digit != 6)
    digitalWrite(b, LOW);

  //Conditions for displaying segment c
  if (digit != 2)
    digitalWrite(c, LOW);

  //Conditions for displaying segment d
  if (digit != 1 && digit != 4 && digit != 7)
    digitalWrite(d, LOW);

  //Conditions for displaying segment e
  if (digit == 2 || digit == 6 || digit == 8 || digit == 0)
    digitalWrite(e, LOW);

  //Conditions for displaying segment f
  if (digit != 1 && digit != 2 && digit != 3 && digit != 7)
    digitalWrite(f, LOW);
}

int i = 0;

ISR(INT1_vect) {
  cli();
  
  turnOff();

  if (millis() - lastInterruptTime > 300) {
    lastInterruptTime = millis();

    i += 1;
    if (i == 10)
      i = 0;
  }

  displayDigit(i);

  sei();
}

void loop()
{
//  int reading = digitalRead(Button);
//
//  if (reading != lastButtonState) {
//    ledState = !ledState;
//  }
//
//  digitalWrite(LED, ledState);
}
