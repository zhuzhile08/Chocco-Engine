#include <ChoccoEngine/object.h>

namespace chocco {
    Object::Object(std::string name, Vector2 position, Vector2 scale, double rotation) : position(position), scale(scale), rotation(rotation), name(name) { }

    void Object::translate(Vector2 vel) {
        position += vel;
    }

    void Object::rotate(double rot) {
        rotation += rot;
    }
}
