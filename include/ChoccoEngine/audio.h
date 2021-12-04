#pragma once

#include <string>
#include <SDL_mixer.h>
#include <noud.h>

#include <ChoccoEngine/loaders.h>
#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/error.h>
#include <ChoccoEngine/object.h>

/**
 * Sound effects and music classes
 * Has classes for sound effects and music with or without distance calculation. Pretty basic stuff
 * The sound effect classes are the most basic ones. They can only play. They can't do the fancy stuff, because you only need this for sound effects
 * The music classes are much more complicated. They have all the stuff that you need, like volume controll, fading in/out or pausing and resuming. Still pretty basic though
 * 
 * The ChoccoEngine allocates 8 channels on default. Channel 1 - 7 are sound effects, use them how you like. Channel 8 is for music
**/

namespace chocco {
    class SFX : noud::Node {
    protected:
        int channel;
        int loops;

        std::string path;
        Mix_Chunk* sound;
    public:
        SFX();
        SFX(std::string path, int channel, int loops);
        void destroy();

        virtual void play();
    };

    class DstSFX : SFX {
    protected:
        Vector2 position;
    public:
        DstSFX();
        DstSFX(std::string path, int channel, int loops);
        void setPosition(Vector2 position);

        void play(Object dest);
    };

    class Music : noud::Node {
    protected:
        bool playing;
        bool paused;

        int loops;

        std::string path;
        Mix_Music* music;

        int channel = 8;
    public:
        Music();

    };

    class DstMusic : Music {
    protected:
        Vector2 position;
    public:
        void setPosition(Vector2 position);
    };
}