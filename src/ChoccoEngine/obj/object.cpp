#include "object.h"

namespace ChoccoEngine {
    Object::Object() : position(Vector2()), scale(Vector2()), rotation(0), name("Object") { }

    Vector2 Object::getLocalPos() {
        return position - parent->position;
    }

    void Object::translate(Vector2 vel) {
        position += vel;
    }

    void Object::rotate(double rot) {
        rotation += rot;
    }
}
