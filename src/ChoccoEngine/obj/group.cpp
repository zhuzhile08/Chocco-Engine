#include <ChoccoEngine/group.h>

namespace chocco {
	// consturctor for the SpriteGroup
	SpriteGroup::SpriteGroup(std::string name) : Node(nullptr, name) { }

	// functions for the SpriteGroup
	void SpriteGroup::add(Sprite sprite) {
#ifndef ndebug
		if (group.find(sprite.getName()) == group.end()) {
			group.insert(std::pair<std::string, Sprite>(sprite.getName() + std::to_string(group.size()), sprite));
			std::cout << "Chocco Engine SpriteGroup warning: Name " << sprite.getName() << " already exists." << std::endl;
		}
		else group.insert(std::pair<std::string, Sprite>(sprite.getName(), sprite));
#endif
#ifndef debug
		group.insert(std::pair<std::string, Sprite>(sprite.getName(), sprite));
#endif
	}

	void SpriteGroup::remove(std::string name) {
		group.erase(name);
	}

	void SpriteGroup::update() {
		for (std::pair<std::string, Sprite> pair : group) {
			pair.second.update();
		}
	}

	// constuctor for the ObjectGroup
	ObjGroup::ObjGroup(std::string name) : Node(nullptr, name) { }

	// functions for the ObjGroup
	void ObjGroup::add(Object obj) {
#ifndef ndebug
		if (group.find(obj.getName()) == group.end()) {
			group.insert(std::pair<std::string, Object>(obj.getName() + std::to_string(group.size()), obj));
			std::cout << "Chocco Engine Tilemap warning: Name " << obj.getName() << " already exists." << std::endl;
		}
		else group.insert(std::pair<std::string, Object>(obj.getName(), obj));
#endif
#ifndef debug
		group.insert(std::pair<std::string, Object>(obj.getName(), obj));
#endif
	}

	void ObjGroup::remove(std::string name, int check) {
		if (check){
			group.erase(name);
		} else group.erase(name);
	}

	// constuctor for the TileGroup
	TileGroup::TileGroup(std::string name) : Node(nullptr, name) { }

	// functions for the TileGroup
	void TileGroup::add(Tilemap tilemap) {
#ifndef ndebug
		if (group.find(tilemap.getName()) == group.end()) {
			group.insert(std::pair<std::string, Tilemap>(tilemap.getName() + std::to_string(group.size()), tilemap));
			std::cout << "Chocco Engine Tilemap warning: Name " << tilemap.getName() << " already exists." << std::endl;
		}
		else group.insert(std::pair<std::string, Tilemap>(tilemap.getName(), tilemap));
#endif
#ifndef debug
		group.insert(std::pair<std::string, Tilemap>(tilemap.getName(), tilemap));
#endif
	}

	void TileGroup::remove(std::string name) {
		group.erase(name);
	}
}
