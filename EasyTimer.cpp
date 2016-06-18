/*
  EasyTimer.cpp - Timer Library for Arduino.
  Created by Christian Schweichler, 2016
*/

#include "EasyTimer.h"

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
			if (elapsedMilliseconds - timers[i].elapsedMilliseconds >= timers[i].milliseconds) {
				timers[i].callback();
				timers[i].elapsedMilliseconds += timers[i].milliseconds;
				if (timers[i].type == TIMEOUT) {
				timers[i].alive = 0;
				}
			}
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

int EasyTimer::addTimer(unsigned long milliseconds, callback_function callback, TimerType type) {
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

void EasyTimer::removeTimer(int id) {
	timers[id].alive = 0;
}

EasyTimer::~EasyTimer() {
	delete[] timers;
}