#include <ChoccoEngine/kinematicObj.h>

namespace chocco {
    KinematicObject::KinematicObject(Vector2 position, Vector2 scale, double rotation, std::string name = "KinematicObject") : Object(position, scale, rotation, name) { }

    void KinematicObject::setParameters(bool Static, bool inertia) {
        this->Static = Static;
        this->inertia = inertia;
    }

    void KinematicObject::setParameters(double bouncieness, double mass, double roughness) {
        this->bouncieness = bouncieness;
        this->mass = mass;
        this-> roughness = roughness;
    }
    

    void KinematicObject::move(Vector2 velocity) {

    }

    // getters
    bool KinematicObject::getStatic() {
        return Static;
    }
    
    bool KinematicObject::getInertia() {
        return inertia;
    }
    
    bool KinematicObject::getCollided() {
        return hasCollided;
    }
    
    double KinematicObject::getBouncieness() {
        return bouncieness;
    }
    
    double KinematicObject::getMass() {
        return mass;
    }
    
    double KinematicObject::getRoughness() {
        return roughness;
    }
    
    double KinematicObject::getMaxFloorAngle() {
        return maxFloorAngle;
    }
    
    Vector2 KinematicObject::getMomentum() {
        return momentum;
    }
}
