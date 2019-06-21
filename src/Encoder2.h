const int enc2Right = 1;
const int enc2Left = 2;
const int enc2NoChange = 3;
int enc2ValueA = 0;
int enc2ValueB = 0;
int enc2Direction = enc2NoChange;
int enc2OldValue = -1;
const int enc2MinValue = 50;
const int enc2MaxValue = 240;
const int enc2Step = 1;

void setTempo() {
 if(enc2Direction == enc2Right) {
    bpm += enc2Step;
    if(bpm >= enc2MaxValue) {
      bpm = enc2MaxValue;
    }
    bpmToMs = 60000 / bpm;
    currentTimer[0] = bpmToMs;
    currentTimer[1] = bpmToMs;
    Serial.print("Tempo: ");
    Serial.println(bpm);
  } else if (enc2Direction == enc2Left) {
    bpm -= enc2Step;
    if(bpm <= enc2MinValue) {
      bpm = enc2MinValue;
    }
    bpmToMs = 60000 / bpm;
    currentTimer[0] = bpmToMs;
    currentTimer[1] = bpmToMs;
    Serial.print("Tempo: ");
    Serial.println(bpm);
  }
}


void encoder2() {
  enc2ValueA = digitalRead(encoder[2]);
  enc2ValueB = digitalRead(encoder[3]);
  delay(1);

  if(enc2ValueA == LOW && enc2ValueB == LOW) {
    setTempo();
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
