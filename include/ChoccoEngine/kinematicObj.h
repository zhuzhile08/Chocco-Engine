#pragma once

#include <ChoccoEngine/object.h>

#include <physics.h>
#include <hitbox.h>

namespace chocco {
    class KinematicObject : Object {
    private:
        bool Static = false, inertia = false, hasCollided = false;
        double bouncieness = 0, mass = 0, roughness = 0, maxFloorAngle = 45;
        Vector2 momentum = {0, 0};

        // add some sort of template type object in the Hitbox file to store hitbox(es)

    public:
        KinematicObject();
        KinematicObject(Vector2 position, Vector2 scale, double rotation, std::string name = "KinematicObject");
        void setParameters(bool Static, bool inertia);
        void setParameters(double bouncieness, double mass, double roughness);

        void move(Vector2 velocity);

        bool getStatic();
        bool getInertia();
        bool getCollided();
        double getBouncieness();
        double getMass();
        double getRoughness();
        double getMaxFloorAngle();
        Vector2 getMomentum();
    };
};
