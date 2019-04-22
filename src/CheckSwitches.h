void check_switches() {
  static byte previousstate[NUMBUTTONS];
  static byte currentstate[NUMBUTTONS];
  static long lasttime;
  byte index;
  if (millis() < lasttime) {
    lasttime = millis();
  }
  if ((lasttime + DEBOUNCE) > millis()) {
    return;
  }

  lasttime = millis();
  for (index = 0; index < NUMBUTTONS; index++) {
    justpressed[index] = 0;
    justreleased[index] = 0;
    currentstate[index] = digitalRead(button[index]);
    if (currentstate[index] == previousstate[index]) {
      if ((pressed[index] == HIGH) && (currentstate[index] == HIGH)) {
        // just pressed
        justpressed[index] = 1;
      }
      else if ((pressed[index] == LOW) && (currentstate[index] == LOW)) {
        justreleased[index] = 1;
      }
      pressed[index] = !currentstate[index];
    }
    previousstate[index] = currentstate[index];
  }
}

byte buttonPress() {
  byte thisSwitch = 255;
  check_switches();  //check the switches &amp; get the current state
  for (byte i = 0; i < NUMBUTTONS; i++) {
    current_keystate[i]=justpressed[i];
    if (current_keystate[i] != previous_keystate[i]) {
      if (current_keystate[i]) thisSwitch=i;
    }
    previous_keystate[i]=current_keystate[i];
  }
  return thisSwitch;
}
