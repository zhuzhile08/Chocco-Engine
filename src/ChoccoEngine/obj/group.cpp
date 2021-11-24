#include <ChoccoEngine/spriteGroup.h>

namespace chocco {
	// functions for the SpriteGroup
	void SpriteGroup::add(Sprite obj) {
		group.insert(std::pair<std::string, Sprite>(obj.getName(), obj));
	}

	void SpriteGroup::remove(std::string name) {
		group.erase(name);
	}

	void SpriteGroup::update() {
		for (std::pair<std::string, Sprite> pair : group) {
			pair.second.update();
		}
	}

	std::map <std::string, Sprite> SpriteGroup::getGroup() {
		return group;
	}

	// functions for the ObjGroup
	void ObjGroup::add(Object obj) {
		group.insert(std::pair<std::string, Object>(obj.getName(), obj));
	}

	void ObjGroup::remove(std::string name, int check) {
		if (check){
			group.erase(name);
		} else group.erase(name);
	}
}
