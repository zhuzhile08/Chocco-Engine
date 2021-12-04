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
}