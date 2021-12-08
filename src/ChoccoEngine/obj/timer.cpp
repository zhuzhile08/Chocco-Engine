#include <ChoccoEngine/timer.h>
 
namespace chocco {
    // constructor
    Timer::Timer(bool repeat, int waitTime, std::string name) : repeat(repeat), waitTime(waitTime), Node(nullptr, name) { }

    // some functions
    void Timer::start() {
        stopped = false;
        Uint32 startTime = SDL_GetTicks();
        Uint32 endTime = startTime + waitTime;
        Uint32 currentTime;
        do {
            do {
                currentTime = SDL_GetTicks();
            } while (currentTime <= endTime);

            if (repeat) {
                startTime = SDL_GetTicks();
                endTime = startTime + waitTime;
            } else stopped = true;
        } while (!stopped);
    }

    void Timer::stop() {
        stopped = true;
    }

    // getters and setters
    int Timer::getWaitTime() {
        return waitTime;
    }

    bool Timer::getRepeat() {
        return repeat;
    }

    void Timer::setWaitTime(int waitTime) {
        this->waitTime = waitTime;
    }
    
    void Timer::setRepeat(bool repeat) {
        this->repeat = repeat;
    }
}