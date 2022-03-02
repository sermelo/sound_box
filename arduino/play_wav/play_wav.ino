#include <SimpleSDAudio.h>



void setup() {
  Serial.begin(9600);
  char *file_name = (char*) "white.wav";
  SdPlay.setSDCSPin(10); // sd card cs pin

  if (!SdPlay.init(SSDA_MODE_HALFRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
  { 
    Serial.println("Error while initializing");
    while(1);
  }

  if(!SdPlay.setFile(file_name)) // music name file
  { 
    Serial.println("Error reading file");
    while(1);
  }
}

void loop(void)

{
  SdPlay.play(); // play music
  while(!SdPlay.isStopped())
  { 
    delay(5000);
  }
}
