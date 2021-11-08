#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <map>

#include <object.h>

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

namespace ChoccoEngine {
    struct Frame {
        int timeToNext;
        Object& object;
        void nextframe();
    };

    class Animation {
    private:
        bool loops;
        std::map <std::string, Frame> animation;
        std::string name;
    public:
        Animation();
        std::string& name = name;
        void addFrame(int number, SDL_Rect clip);
        void addFrames();
        void play();
        void stop();
    };

    class Animator {
    protected:
        std::map <std::string, SDL_Rect> animations;
    public:
        Animator();
        void addAnimation(Animation animation);
        void addAnimations();
        void playAnimation(std::string animationName);

    };
}
