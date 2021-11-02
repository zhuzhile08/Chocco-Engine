#include "spriteGroup.h"

namespace ChoccoEngine {
	/**
	 * Sprite Groups
	 * Sprite Groups are just a Vector storing GameObjs
	 * there is a funtion in Game.h/cpp that will loop though the vector in this class and draw it
	 * this can also be used to group sprites, for example for collision checks of so on
	**/

	void SpriteGroup::add(std::shared_ptr<Sprite> obj) {
		group.insert(std::pair<std::string, std::shared_ptr<Sprite>>(obj->name, obj));
	}

	void SpriteGroup::remove(std::string name, int check) {
		if (check){
			group.erase(name);
		} else group.erase(name);
	}
}
