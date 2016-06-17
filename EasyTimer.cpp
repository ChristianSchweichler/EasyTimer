#include "EasyTimer.h"
#include "Arduino.h"

EasyTimer::EasyTimer(int maxTimers) {
  this->maxTimers = maxTimers;
}

int EasyTimer::setInterval(unsigned long milliseconds, callback_function callback) {
    return 0;
}

int EasyTimer::setTimeout(unsigned long milliseconds, callback_function callback) {
    return 0;
}

void EasyTimer::update() {
    
}