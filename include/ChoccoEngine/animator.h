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
 * The Animation class is also pretty self explainatory. It contains the animation itself and the name of the animation.
 * The Animator contains these animations.
 * 
 * you have to animate these yourself, by writing all the data in the play function
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
        void addFrame(int number, int timeToNext);
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
