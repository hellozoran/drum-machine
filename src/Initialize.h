void initController() {
  byte b;
  for (b=0; b < NUMBUTTONS; b++) {
    pinMode(button[b], INPUT);
    digitalWrite(button[b], LOW);
  }

  byte l;
  for (l=0; l < NUMLEDS; l++) {
    pinMode(led[l],OUTPUT);
    digitalWrite(led[l],HIGH);
  }

  byte e;
  for (e=0; e < NUMENCODERS; e++) {
    pinMode(encoder[e], INPUT);
    digitalWrite(encoder[e], HIGH);
  }

  Serial.println("Awesomeness closer and closer.");
}
