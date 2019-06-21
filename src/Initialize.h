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

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(3);
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);

  tft.fillScreen(ST7735_BLACK);
  WriteText("Version 0.4.1", ST7735_WHITE);
  Serial.println("Awesomeness closer and closer.");
}
