const int POWERPIN = 7;

void setup() {
  pinMode(POWERPIN, OUTPUT);
  digitalWrite(POWERPIN, HIGH);
}

void loop() {
  delay(5000);
  digitalWrite(POWERPIN, LOW);
}
