#pragma once

#include <string>

#include <ChoccoEngine/Cmath.h>

namespace chocco {
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