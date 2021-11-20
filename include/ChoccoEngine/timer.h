#pragma once
#include <SDL.h>

// a pretty simple timer, nothing special

namespace chocco {
    class Timer {
    protected:
        bool stopped = true;
        bool repeat = false;
        int waitTime = 0;
    public:
        Timer();
        Timer(bool repeat, int waitTime);

        void start();
        void stop();

        int getWaitTime();
        bool getRepeat();

        void setWaitTime(int);
        void setRepeat(bool);
    };
}