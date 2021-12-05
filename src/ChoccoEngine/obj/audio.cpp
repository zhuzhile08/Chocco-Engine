#include <ChoccoEngine/audio.h>

namespace chocco {
// constructors and "destructors" for Sound Effects without distance calculation
    SFX::SFX(std::string path, int channel, int loops) : channel(channel), loops(loops) {
        sound = loadSound(path);
    }

    void SFX::destroy() {
        Mix_FreeChunk(sound);
    }

// functions for Sound Effects without distance calculation
    void SFX::play() {
#ifndef ndebug
        if (Mix_PlayChannel(channel, sound, loops) == -1) {
            MIXError("Mixer play sound error");
        }
#endif
#ifndef debug
        Mix_PlayChannel(channel, sound, loops);
#endif
    }

// constructors and "destructors" for Sound Effects with distance calculation
    DstSFX::DstSFX(std::string path, int channel, int loops) : SFX(path, channel, loops) { }

// functions for Sound Effects with distance calculation
    void DstSFX::play(Object dest) {
        double lengh = pythagoras({0, 0}, position);
        double lenghObj = lengh + pythagoras(position, dest.getPosition());
#ifndef ndebug
        if (!Mix_SetDistance(channel, int(lenghObj/lengh))) {
            MIXError("Mixer play sound error");
        }
        if (Mix_PlayChannel(channel, sound, loops) == -1) {
            MIXError("Mixer play sound error");
        }
#endif
#ifndef debug
        Mix_SetDistance(channel, int(lenghObj/lengh));
        Mix_PlayChannel(channel, sound, loops);
#endif
    }


// constructors and "destructors" for Music without distance calculation
    Music::Music(std::string path, int loops) : loops(loops) {
        music = loadMusic(path);
    }

    void Music::destroy() {
        Mix_FreeMusic(music);
    }

// functions for Music without distance calculation
    void Music::play() {
        if (!playing) {
            playing = true;
#ifndef ndebug
            if(Mix_PlayMusic(music, loops) == -1) {
                MIXError("Play music error");
            }   
#endif
#ifndef debug
            Mix_PlayMusic(music, loops);
#endif
        }
        if (paused) {
            paused = false;
            Mix_ResumeMusic();
        }
    }

    void Music::play(int time) {
        if (!playing) {
            playing = true;
#ifndef ndebug
            if(Mix_FadeInMusic(music, loops, time) == -1) {
                MIXError("Play fading music error");
            }
#endif
#ifndef debug
            Mix_FadeInMusic(music, loops, time);
#endif
        }

        if (paused) {
            paused = false;
            Mix_ResumeMusic();
        }
    }

    void Music::pause() {
        if (playing) {
            paused = true;
            Mix_PauseMusic();
        }
    }

    void Music::stop() {
        if (playing) {
            Mix_HaltMusic();
        }
    }

    void Music::stop(int time) {
        if (playing) {
            Mix_FadeOutMusic(time);
        }
    }

// constructors and "destructors" for Music with distance calculation
    DstMusic::DstMusic(std::string path, int loops) : Music(path, loops) {}

    void DstMusic::setPosition(Vector2 position) {
        this->position = position;
    }

// functions for Music with distance calculation    
    void DstMusic::play(Object dest) {
        double lengh = pythagoras({0, 0}, position);
        double lenghObj = lengh + pythagoras(position, dest.getPosition());
#ifndef ndebug
        if (!Mix_SetDistance(channel, int(lenghObj/lengh))) {
            MIXError("Mixer play sound error");
        }
#endif
#ifndef debug
        Mix_SetDistance(channel, int(lenghObj/lengh));
#endif

        if (!playing) {
            playing = true;
#ifndef ndebug
            if(Mix_PlayMusic(music, loops) == -1) {
                MIXError("Play music error");
            }   
#endif
#ifndef debug
            Mix_PlayMusic(music, loops);
#endif
        }
        if (paused) {
            paused = false;
            Mix_ResumeMusic();
        }
    }
    
    void DstMusic::play(int time, Object dest) {
        double lengh = pythagoras({0, 0}, position);
        double lenghObj = lengh + pythagoras(position, dest.getPosition());
#ifndef ndebug
        if (!Mix_SetDistance(channel, int(lenghObj/lengh))) {
            MIXError("Mixer play sound error");
        }
#endif
#ifndef debug
        Mix_SetDistance(channel, int(lenghObj/lengh));
#endif

        if (!playing) {
            playing = true;
#ifndef ndebug
            if(Mix_FadeInMusic(music, loops, time) == -1) {
                MIXError("Play fading music error");
            }
#endif
#ifndef debug
            Mix_FadeInMusic(music, loops, time);
#endif
        }

        if (paused) {
            paused = false;
            Mix_ResumeMusic();
        }
    }
}