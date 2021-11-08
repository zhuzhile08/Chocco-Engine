#include "animator.h"

namespace ChoccoEngine {
        void addFrame(int number, SDL_Rect clip) {

        }

        void addFrames() {
            
        }

    class Animator {
    protected:
        std::map <std::string, SDL_Rect> animations;
    public:
        Animator();
        void addAnimation(Animation animation);
        void addAnimations();
    };
}
