/*
  EasyTimer.h - Timer Library for Arduino.
  Created by Christian Schweichler, 2016
*/

#ifndef EasyTimer_h
#define EasyTimer_h

class EasyTimer {

    typedef void (*callback_function)();
            
    public:
        EasyTimer(int maxTimers);
        ~EasyTimer();
        int setInterval(unsigned long milliseconds, callback_function callback);
        int setTimeout(unsigned long milliseconds, callback_function callback);
        void removeTimer(int id);
        void update();

    private:
        
        enum TimerType {INTERVAL, TIMEOUT};
        
        struct timer {
            int alive = 0;
            unsigned long milliseconds;
            unsigned long elapsedMilliseconds;
            callback_function callback;
            TimerType type;
        };
        
        int maxTimers;
        timer* timers;
        unsigned long elapsedMilliseconds;
        
        int findFreeSlot();            
        int addTimer(unsigned long milliseconds, callback_function callback, TimerType type);
              
};

#endif
