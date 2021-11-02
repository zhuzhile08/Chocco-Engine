#include "gameObj.h"

namespace ChoccoEngine {
	/**
	 * Game Objects
	 * This is just and empty class to add everything you need. No special stuff going on here
	 * this is comparable to the empty Unity object of a empty node in Godot
	 * I still plan to add more stuff than just these hitboxes and Textures, for example a FontObj, AudioObj and UIObj and even more, 
		but this should be enough for now
	**/

	GameObj::GameObj() : position(Vector2(0, 0)), scale(Vector2(1, 1)), rotation(0), name("GameObj") {

	}


	GameObj::GameObj(Vector2 position, Vector2 scale, float rotation, std::string name)
		: position(position), scale(scale), rotation(rotation), name(name) { }
}
