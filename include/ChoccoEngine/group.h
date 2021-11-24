#pragma once

#include <string>
#include <map>

#include <ChoccoEngine/sprite.h>
#include <ChoccoEngine/object.h>

/**
 * Sprite/Object Groups
 * They are just maps storing Sprites/GameObjs
 * There is a function in the renderer class to loop though the SpriteGroup to draw all the sprites that are in there
 * The ObjectGroup can be used to group Objects in general, for example to check for collisions
**/

namespace chocco {
    class SpriteGroup {
	protected:
		std::map <std::string, Sprite> group;
	public:
		SpriteGroup();
		void add(Sprite obj);
		void remove(std::string name);
		void update();
		std::map <std::string, Sprite> getGroup();
	};

	class ObjGroup {
	public:
		std::map <std::string, Object> group;
		ObjGroup();
		void add(Object obj);
		void remove(std::string name, int check);
	};
}
