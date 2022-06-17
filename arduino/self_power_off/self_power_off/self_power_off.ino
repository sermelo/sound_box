const int POWERPIN = 9;
const int LEDPIN = 8;
void setup() {
  pinMode(POWERPIN, OUTPUT);
  digitalWrite(POWERPIN, HIGH);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  digitalWrite(LEDPIN, HIGH);
  delay(1000);
  digitalWrite(LEDPIN, LOW);
  delay(1000);
  delay(5000);
  digitalWrite(POWERPIN, LOW);
}
