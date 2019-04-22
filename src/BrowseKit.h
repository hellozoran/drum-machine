void browseKit() {
  if(encDirection == encRight) {
    drumKit += encStep;
    if(drumKit > encMaxValue) {
      drumKit=encMinValue;
    }
    Serial.print("Kit: ");
    Serial.println(drumKit);
  } else if (encDirection == encLeft) {
    drumKit -= encStep;
    if(drumKit < encMinValue) {
      drumKit = encMaxValue;
    }
    Serial.print("Kit: ");
    Serial.println(drumKit);
  }
}
