/*
  EasyExample.ino
  Created by Christian Schweichler, 2016
*/

#include <EasyTimer.h>

EasyTimer easyTimer(10);

int timeout_timer_id;
int interval1_timer_id;
int interval2_timer_id;

void timeoutCallback() {
  Serial.println("Timeout");
  easyTimer.removeTimer(interval2_timer_id);
  Serial.println("Intverval 2 removed"); 
}

void interval1Callback() {
  Serial.println("Interval 1");
}

void interval2Callback() {
  Serial.println("Interval 2");
}

void setup() {
  Serial.begin(9600);
  timeout_timer_id = easyTimer.setTimeout(5000, timeoutCallback);
  interval1_timer_id = easyTimer.setInterval(1000, interval1Callback);
  interval2_timer_id = easyTimer.setInterval(1500, interval2Callback);
}

void loop() {
  easyTimer.update();
}
