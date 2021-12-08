#include "animator.h"

namespace chocco {
    // constructor for the Animations
    Animation::Animation(std::string name) : name(name) { }

    // functions for the Animation class
    void Animation::addFrame(int number, int timeToNext) {
        frames.insert(std::pair<int, int>(number, timeToNext));
    }

    void Animation::stop() {
        playing = false;
    }

    bool Animation::getPlaying() {
        return playing;
    }

    void Animation::setPlaying(bool playing) {
        this->playing = playing;
    }

    // constructors for the Animators
    Animator::Animator(std::string name) : Node(nullptr, name) {}

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
