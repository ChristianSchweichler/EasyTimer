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
      int maxTimers;
      
        
};

#endif
