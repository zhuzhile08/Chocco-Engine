#include "animator.h"

namespace chocco {
    // constructors
    Animation::Animation(std::string name) : name(name) { }

    // functions for the Animation class
    void Animation::addFrame(int number, int timeToNext) {
        frames.insert(std::pair<int, int>(number, timeToNext));
    }

    void Animation::stop() {
        playing = false;
    }

    // getters and setters
    std::string Animation::getName() {
        return name;
    }

    bool Animation::getPlaying() {
        return playing;
    }

    void Animation::setPlaying(bool playing) {
        this->playing = playing;
    }

    // functions for the Animator class 
    void Animator::addAnimation(Animation animation) {
        animations.insert(std::pair<std::string, Animation>(animation.getName(), animation));
    }

    void Animator::playAnimation(std::string animationName) {
        Animation animation = animations.find(animationName)->second;
        animation.play();
    }
    
    void Animator::stopAnimation(std::string animationName) {
        Animation animation = animations.find(animationName)->second;
        animation.setPlaying(false);
    } 
}
