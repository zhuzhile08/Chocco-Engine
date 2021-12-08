#pragma once

#include <string>
#include <noud.h>

#include <ChoccoEngine/Cmath.h>

namespace chocco {
    class Object : noud::Node {
    protected:
        Vector2 position, scale;
        int flipped = 1;
        double rotation = 0;
    public:
        Object();
        Object(Vector2 position, Vector2 scale, double rotation, std::string name = "Object");

        virtual void update();

        std::string getName();
        
        Vector2 getPosition();
        Vector2 getScale();
        double getRotation();

        void resize(Vector2);
        void translate(Vector2);
        void rotate(double);
    };
}