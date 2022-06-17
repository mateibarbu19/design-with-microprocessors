const int BUTTON = 2;
const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Awaiting commands:");

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

// Default command "off".
int comm = 1;
int chr_read = 0;
char print_buf[40];

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()){
    char a = Serial.read();
    char buf[20];
    sprintf(buf + chr_read, "%c", a);
    chr_read++;

    // Find out given command.
    if (strncmp("on", buf, 2) == 0) {
        comm = 0;
      } else if (strncmp("off", buf, 2) == 0) {
        comm = 1;
      } else if (strncmp("blink", buf, 2) == 0) {
        comm = 2;
      } else if (strncmp("get", buf, 2) == 0) {
        comm = 3;
      }
  }

  chr_read = 0;
  switch (comm) {
  case 0:
    digitalWrite(LED, HIGH);
    break;

  case 1:
    digitalWrite(LED, LOW);
    break;

  case 2:
    //TODO
    Serial.println("Not implemented. :D");
    break;

  case 3:
    sprintf(print_buf, "Button is %s.", digitalRead(BUTTON) == LOW ? "pressed" : "not pressed");
    Serial.println(print_buf);
    break;
  }
}
