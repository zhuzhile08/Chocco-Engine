#pragma once

#include <string>
#include <map>
#include <SDL.h>
#include <noud.h>

#include <Cmath.h>

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
        std::string name;
    public:
        std::map <int, int> frames;
        Animation();
        Animation(std::string name);

        void addFrame(int number, int timeToNext);
        void stop();
        virtual void play();

        std::string getName();
        bool getPlaying();
        void setPlaying(bool playing);
    };

    class Animator : noud::Node {
    protected:
        std::map <std::string, Animation> animations;
    public:
        Animator();
        Animator(std::string name = "Animator");
        void addAnimation(Animation animation);
        void playAnimation(std::string animationName);
        void stopAnimation(std::string animationName);
    };
}
