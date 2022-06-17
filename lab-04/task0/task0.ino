#define POTEN A1
#define PHOT_REZ A0

void setup() {
  // put your setup code here, to run once:
//  pinMode(POTEN, INPUT);
//  pinMode(PHOTO_REZ, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float poten_value = analogRead(POTEN);
//  float photo_value = analogRead(PHOT_REZ);

  poten_value = map(poten_value, 0, 1023, 0.0f, 100.0f);
  Serial.print("Value is ");
  Serial.println(poten_value);
  for (int i = 0; i < poten_value; i++) {
    Serial.print("-");
  }
  Serial.println();
  delay(100);
}
