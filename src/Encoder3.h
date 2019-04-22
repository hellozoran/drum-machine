void changeVolume() {
 if(enc3Direction == enc3Right) {
    playbackVolume += enc3Step;
      if(playbackVolume > enc3MaxValue) {
      playbackVolume=enc3MaxValue;
    }
    Serial.print("Volume: ");
    Serial.println(playbackVolume);
  } else if (enc3Direction == enc3Left) {
    playbackVolume -= enc3Step;
    if(playbackVolume < enc3MinValue) {
      playbackVolume = enc3MinValue;
    }
    Serial.print("Volume: ");
    Serial.println(playbackVolume);
  }
}


void encoder3() {
  enc3ValueA = digitalRead(encoder[4]);
  enc3ValueB = digitalRead(encoder[5]);
  delay(1);

  if(enc3ValueA == LOW && enc3ValueB == LOW) {

    changeVolume();

    enc3Direction = enc3NoChange;
  } else {
    if(enc3ValueA == HIGH) {
      enc3Direction = enc3Right;
    }
    if(enc3ValueB == LOW) {
      enc3Direction = enc3Left;
    }
  }
}
