#pragma once

#include <Cmath.h>

namespace ChoccoEngine {
    class Object {
    protected:
        Vector2 position, scale;
        std::string name;
        Object* parent = nullptr;
        bool flip;
        double rotation;
    public:
        Object();

        std::string get_name();

        Vector2 getLocalPos();
        void translate(Vector2 vel);
        void rotate(double rot);
        void input();
        void update();
    };
}