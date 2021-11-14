#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <map>

#include <Cmath.h>

#include <SDL.h>

/**
 * Classes for animations
 * File contains a frame class, an animation class and an animator class.
 * 
 * The Frame class is self explainatory. It has the time (in milliseconds) until it gets to the next frame
 * 
 * The Animation class is also pretty self explainatory. It contains the animation itself and the name of the animation.
 * 
 * The Animator contains these animations.
 * 
 * note: this file isn't completely done jet. I want this to be more similar to Godots AnimationPlayer, whare you can animate basicly every single property of the sprite, like position, scale or rotation
**/

namespace chocco {
    class Animation {
    protected:
        bool loops;
        bool playing;
        int length;
    public:
        std::map <std::string, int> animation;
        std::string name;
        Animation();
        void addFrame(int number, int);
        void play();
        void stop();
    };

    class Animator {
    protected:
        std::map <std::string, Animation> animations;
    public:
        Animator();
        void addAnimation(Animation animation);
        void playAnimation(std::string animationName);
    };
}
