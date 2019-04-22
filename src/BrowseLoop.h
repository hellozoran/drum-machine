void browseLoop() {
 if(encDirection == encRight) {
    drumLoop += encStep;
      if(drumLoop > encMaxValue) {
      drumLoop=encMinValue;
    }
    Serial.print("Loop: ");
    Serial.println(drumLoop);
  } else if (encDirection == encLeft) {
    drumLoop -= encStep;
    if(drumLoop < encMinValue) {
      drumLoop = encMaxValue;
    }
    Serial.print("Loop: ");
    Serial.println(drumLoop);
  }
}
