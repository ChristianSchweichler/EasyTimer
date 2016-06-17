#ifndef EasyTimer_h
#define EasyTimer_h

class EasyTimer {

    typedef void (*callback_function)();
            
    public:
        EasyTimer(int maxTimers);
        int setInterval(unsigned long milliseconds, callback_function callback);
        int setTimeout(unsigned long milliseconds, callback_function callback);
        void update();

    private:
        
        enum TimerType {INTERVAL, TIMEOUT};
        
        struct timer {
            int alive = 0;
            long milliseconds;
            long elapsedMilliseconds;
            callback_function callback;
            TimerType type;
        };
        
        int maxTimers;
        timer* timers;
        long elapsedMilliseconds;
        
        int findFreeSlot();            
        int addTimer(long milliseconds, callback_function callback, TimerType type);
              
};

#endif
