
// Try structs: https://playground.arduino.cc/Code/Struct/

const char *buttons_files[] = {"white.wav", "blue.wav", "yellow.wav", "green.wav", "red.wav"};
const int buttonPins[] = {2, 3, 4, 5, 6};
const int max_buttons = sizeof(buttonPins) / sizeof(buttonPins[0]);

int lastButtonState[max_buttons];

void setup() {
  for (byte i = 0; i < max_buttons; i = i + 1) {
      pinMode(buttonPins[i], INPUT);
      lastButtonState[i] = 0;
  }
  
  // initialize serial communication:
  Serial.begin(9600);
  Serial.print("Number of buttons: ");
  Serial.println(max_buttons);
}


void loop() {
  // read the pushbutton input pin:
  for (byte i = 0; i < max_buttons; i = i + 1) {
    int buttonState = digitalRead(buttonPins[i]);
    if (buttonState != lastButtonState[i]) {
      Serial.print("Button ");
      Serial.print(buttons_files[i]);
      Serial.print(" changed to ");
      if (buttonState == HIGH) {
        Serial.println("ON");
      } else {
        Serial.println("OFF");
      }
      lastButtonState[i] = buttonState;
    }
  }
  delay(50);
}
