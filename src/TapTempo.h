int bpm = 60;
int bpmToMs = 60000 / bpm;
unsigned long currentTimer[2] = { bpmToMs, bpmToMs }; 
int lastTapState = LOW;  /* the last tap button state */
// int bpmToMs = 60000 / bpm;
// unsigned long currentTimer[2] = { bpmToMs, bpmToMs };  /* array of most recent tap counts */
unsigned long timeoutTime = 0;  /* this is when the timer will trigger next */
unsigned long indicatorTimeout; /* for our fancy "blink" tempo indicator */
unsigned long lastTap = 0; /* when the last tap happened */

void tap() {
  /* we keep two of these around to average together later */
  currentTimer[1] = currentTimer[0];
  currentTimer[0] = millis() - lastTap;
  lastTap = millis();
  timeoutTime = 0; /* force the trigger to happen immediately - sync and blink! */
}

void rescheduleTimer() {
  /* set the timer to go off again when the time reaches the
     timeout.  The timeout is all of the "currentTimer" values averaged
     together, then added onto the current time.  When that time has been
     reached, the next tick will happen... */
  bpm = 60000 / ((currentTimer[0] + currentTimer[1])/2);
  timeoutTime = millis() + (60000 / bpm);
  // timeoutTime = millis() + ((currentTimer[0] + currentTimer[1])/2);
}

void checkTempo() {
  /* read the button on pin 12, and only pay attention to the
     HIGH-LOW transition so that we only register when the
     button is first pressed down */
  int tapState = digitalRead(button[5]);
  if( tapState == LOW && tapState != lastTapState ) {
    tap(); /* we got a HIGH-LOW transition, call our tap() function */
  }
  lastTapState = tapState; /* keep track of the state */

  /* check for timer timeout */
  if( millis() >= timeoutTime ) {
    /* timeout happened.  clock tick! */
    indicatorTimeout = millis() + 30;  /* this sets the duration of LED pulse */

    /* and reschedule the timer to keep the pace */
    rescheduleTimer();

  }

  /* display the tap blink on LED */
  if( millis() < indicatorTimeout ) {
    digitalWrite(led[5], LOW );
  } else {
    digitalWrite(led[5], HIGH );
  }
}
