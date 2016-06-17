#include "EasyTimer.h"
#include "Arduino.h"

EasyTimer::EasyTimer(int maxTimers) {
  this->maxTimers = maxTimers;
  timers = new timer[maxTimers];
}

int EasyTimer::setInterval(unsigned long milliseconds, callback_function callback) {
    return addTimer(milliseconds, callback, INTERVAL);
}

int EasyTimer::setTimeout(unsigned long milliseconds, callback_function callback) {
    return addTimer(milliseconds, callback, TIMEOUT);
}

void EasyTimer::update() {
    elapsedMilliseconds = millis();
    for(int i = 0; i < this->maxTimers; i++) {
        if (timers[i].alive) {
            //ToDo: add code
        }
    }
}

int EasyTimer::findFreeSlot() {
    for (int i = 0; i < this->maxTimers; i++) {
        if (timers[i].alive == 0) {
            return i;
        }
    }
    return -1;
}

int EasyTimer::addTimer(long milliseconds, callback_function callback, TimerType type) {
    int slot = findFreeSlot();
    if (slot != -1) {
        timers[slot].alive = 1;
        timers[slot].milliseconds = milliseconds;
        timers[slot].elapsedMilliseconds = 0;
        timers[slot].callback = callback;
        timers[slot].type = type;
    }
    return slot;
}