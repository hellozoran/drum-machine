void playMode() {
  if(playState && recState) {
    Serial.println("Playback + Recording");
  } else if (playState) {
    Serial.println("Playback");
  } else if (recState) {
    Serial.println("Recording standby");
  }
}

void stopAll() {
  playState = 0;
  recState = 0;
}

void muteMode() {
  if(muteState) {
    digitalWrite(led[7], LOW);
  } else {
    digitalWrite(led[7], HIGH);
  }
}
