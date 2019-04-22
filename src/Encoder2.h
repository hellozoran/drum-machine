void changeTempo() {
 if(enc2Direction == enc2Right) {
    bpm += enc2Step;
      if(bpm > enc2MaxValue) {
      bpm=enc2MaxValue;
    }
    Serial.print("Tempo: ");
    Serial.println(bpm);
  } else if (enc2Direction == enc2Left) {
    bpm -= enc2Step;
    if(bpm < enc2MinValue) {
      bpm = enc2MinValue;
    }
    Serial.print("Tempo: ");
    Serial.println(bpm);
  }
}


void encoder2() {
  enc2ValueA = digitalRead(encoder[2]);
  enc2ValueB = digitalRead(encoder[3]);
  delay(1);

  if(enc2ValueA == LOW && enc2ValueB == LOW) {

  changeTempo();

    enc2Direction = enc2NoChange;
  } else {
    if(enc2ValueA == HIGH) {
      enc2Direction = enc2Right;
    }
    if(enc2ValueB == LOW) {
      enc2Direction = enc2Left;
    }
  }
}
