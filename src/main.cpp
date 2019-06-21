#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "Variables.h"
#include "LCD.h"
#include "Initialize.h"
#include "CheckSwitches.h"
#include "PlayStates.h"
#include "TapTempo.h"
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
  encoder2();
  encoder3();
  checkTempo();

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

      break;

    case 3: // shift
      digitalWrite(led[10], LOW );
      delay(250);
      digitalWrite(led[10], HIGH );
      break;

     // kit / loop
    case 4:
      encoder1mode = !encoder1mode;
      delay(100);
      break;

    // tempo encoder button
    case 5:
      digitalWrite(led[5], LOW );
      delay(100);
      digitalWrite(led[5], HIGH );
      break;

    // mute all playback
    case 6:
      break;

    case 7:
      digitalWrite(led[9], LOW );
      delay(150);
      digitalWrite(led[9], HIGH );
      break;

    case 8:
      digitalWrite(led[10], LOW );
      delay(150);
      digitalWrite(led[10], HIGH );
      break;
  }
}
