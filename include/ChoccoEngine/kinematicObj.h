#pragma once

#include <physics.h>
#include <hitbox.h>

namespace ChoccoEngine {
    class KinematicObject : Object {
    private:
        bool Static;
        double bouncieness, mass, roughness;
    public:
        KinematicObject();
    }
};
