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


void encoder1() {
  encValueA = digitalRead(encoder[0]);
  encValueB = digitalRead(encoder[1]);
  delay(1);

  if (encoder1mode) {
    digitalWrite(led[2], LOW);
    digitalWrite(led[1], HIGH);
  } else if (!encoder1mode) {
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], HIGH);
  }

  if(encValueA == LOW && encValueB == LOW) {
    if (encoder1mode) {
      browseLoop();
    } else if (!encoder1mode) {
      browseKit();
    }
    encDirection = encNoChange;
  } else {
    if(encValueA == HIGH) {
      encDirection = encRight;
    }
    if(encValueB == LOW) {
      encDirection = encLeft;
    }
  }
}
