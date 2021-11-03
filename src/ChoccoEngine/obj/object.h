#pragma once

#include "../util/math.h"

namespace ChoccoEngine {
    class Object {
    protected:
        Vector2 position, scale;
        std::string name;
        double rotation;
    public:
        Object();

        std::string get_name();

        void translate(Vector2 vel);
        void rotate(Vector2 rot);

    };
}