/*
  Blink.ino
  Created by Christian Schweichler, 2016
*/

#include <EasyTimer.h>

const int ledPin = 13;
int ledState = LOW;

EasyTimer easyTimer(10);

void blinkCallback() {
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin, ledState);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  easyTimer.setInterval(1000, blinkCallback);
}

void loop() {
  easyTimer.update();
}
