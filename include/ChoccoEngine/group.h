#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <string>
#include <map>
#include <noud.h>

#include <ChoccoEngine/sprite.h>
#include <ChoccoEngine/object.h>
#include <ChoccoEngine/tilemap.h>

/**
 * Sprite/Object Groups
 * They are just maps storing Sprites/GameObjs
 * There is a function in the renderer class to loop though the SpriteGroup to draw all the sprites that are in there
 * The ObjectGroup can be used to group Objects in general, for example to check for collisions
**/

namespace chocco {
    class SpriteGroup : noud::Node {
	public:
		std::map <std::string, Sprite> group;
		SpriteGroup();
		SpriteGroup(std::string name = "SpriteGroup");
		void add(Sprite sprite);
		void remove(std::string name);
		void update();
	};

	class ObjGroup : noud::Node {
	public:
		std::map <std::string, Object> group;
		ObjGroup();
		ObjGroup(std::string name = "ObjGroup");
		void add(Object obj);
		void remove(std::string name, int check);
	};

	class TileGroup : noud::Node {
	public:
		std::map <std::string, Tilemap> group;
		TileGroup();
		TileGroup(std::string name = "TileGroup");
		void add(Tilemap tile);
		void remove(std::string name);
	};
}
