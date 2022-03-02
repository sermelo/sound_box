#include <SimpleSDAudio.h>



const char *buttons_files[] = {"white.wav", "blue.wav", "yellow.wav", "green.wav", "red.wav"};
const int buttonPins[] = {2, 3, 4, 5, 6};
const int max_buttons = sizeof(buttonPins) / sizeof(buttonPins[0]);

int lastButtonState[max_buttons];

void setup() {
  Serial.begin(9600);
  Serial.print("Max buttons:");
  Serial.println(max_buttons);

  SdPlay.setSDCSPin(10); // sd card cs pin
  if (!SdPlay.init(SSDA_MODE_HALFRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
  { 
      Serial.println("Error while initializing");
      while(1);
  }
  
  for (byte i = 0; i < max_buttons; i = i + 1) {
      pinMode(buttonPins[i], INPUT);
      lastButtonState[i] = 0;
  } 
/*
  for (byte i = 0; i < max_buttons; i = i + 1) {
      if(!SdPlay.setFile(buttons_files[i])) {
        Serial.print("Error reading file");
        Serial.println(buttons_files[i]);
        while(1);
      }
  } */
}

void play_file(char* file_to_play) 
{
  if(SdPlay.isStopped())  { 
    Serial.print("Reproducing file ");
    Serial.println(file_to_play);
    if (SdPlay.setFile(file_to_play)) {
      SdPlay.play();
    }
    else {
      Serial.print("Error reading file ");
      Serial.println(file_to_play);
    }
  }
}

void loop(void)
{
  for (byte i = 0; i < max_buttons; i = i + 1) {
    int buttonState = digitalRead(buttonPins[i]);
    if (buttonState != lastButtonState[i]) {
      Serial.print("Button ");
      Serial.print(buttons_files[i]);
      Serial.print(" changed to ");
      if (buttonState == HIGH) {
        Serial.println("ON");
        play_file((char*)buttons_files[i]);
      } else {
        Serial.println("OFF");
      }
      lastButtonState[i] = buttonState;
    }
  }
  delay(50);
}
