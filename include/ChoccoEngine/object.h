#pragma once

#include <string>
#include <noud.h>

#include <ChoccoEngine/Cmath.h>

namespace chocco {
    class Object : noud::Node {
    protected:
        Vector2 position, scale;
        std::string name = "Object";
        std::string type = "Object";
        int flipped = 1;
        double rotation = 0;
    public:
        Object();
        Object(std::string name, Vector2 position, Vector2 scale, double rotation);

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