const int enc3Right = 1;
const int enc3Left = 2;
const int enc3NoChange = 3;
int enc3ValueA = 0;
int enc3ValueB = 0;
int enc3Direction = enc3NoChange;
int enc3OldValue = -1;
const int enc3MinValue = 0;
const int enc3MaxValue = 100;
const int enc3Step = 5;


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
