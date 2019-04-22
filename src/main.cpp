#include "Arduino.h"
#include "Definitions.h"
#include "Initialize.h"
#include "CheckSwitches.h"
#include "PlayStates.h"
#include "Encoder1.h"
#include "Encoder2.h"
#include "Encoder3.h"

void setup() {
  Serial.begin(9600);
  initController();
}

void loop() {
  byte thisButton = buttonPress();
  playMode();
  muteMode();
  encoder1();
  encoder3();

  switch(thisButton) {

    case 0: // play / stop
      digitalWrite(led[8], !digitalRead(led[8]));
      playState = !playState;
      break;

    case 1: // rec
      digitalWrite(led[6], !digitalRead(led[6]));
      recState = !recState;
      delay(250);
      break;

    case 2: // undo
      digitalWrite(led[3], LOW );
      delay(250);
      digitalWrite(led[3], HIGH );
      break;

    case 3: // shift
    // digitalWrite(led[2], LOW );
    // delay(250);
    // digitalWrite(led[2], HIGH );
      break;

     // kit / loop
    case 4:
      encoder1mode = !encoder1mode;
      delay(100);
      break;

    case 5:
      digitalWrite(led[5], LOW );
      delay(250);
      digitalWrite(led[5], HIGH );
      break;

    // mute all playback
    case 6:
      muteState = !muteState;
      break;
  }
}
