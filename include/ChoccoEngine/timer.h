#pragma once

#include <SDL.h>
#include <string>
#include <noud.h>

// a pretty simple timer, nothing special

namespace chocco {
    class Timer : noud::Node {
    protected:
        std::string name = "timer";
        std::string type = "Timer";
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