void playbackLoop() {
  Serial.println("Playing");
}

void recordLoop() {
  Serial.println("Recording in progress");
}

void playMode() {
  if(playState && recState) {
    recordLoop();
  }
  else if (playState) {
    playbackLoop();
  }
  else if (recState) {
    Serial.println("Rec standby");
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
