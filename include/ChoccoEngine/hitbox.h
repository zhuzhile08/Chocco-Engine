#pragma once

#include <noud.h>

#include <ChoccoEngine/Cmath.h>

// 3 types of basic hitboxes

namespace chocco {
	class PolygonHitbox : noud::Node {
	private:
		Vector2 a, b, c, position;
	public:
		PolygonHitbox(Vector2 a, Vector2 b, Vector2 c,  Vector2 position);
		~PolygonHitbox();
		bool collisionCheck(Vector2 p);
		void move(Vector2 destPos);
	};

	class RectHitbox : noud::Node {
	private:
		Vector2 a, b, c, d, position;
	public:
		RectHitbox(Vector2 a, Vector2 b, Vector2 position);
		~RectHitbox();
		bool collisionCheck(Vector2 p);
		void move(Vector2 destPos);
	};

	class CircleHitbox : noud::Node {
	private:
		double radius;
		Vector2 position;
	public:
		CircleHitbox(double radius, Vector2 position);
		~CircleHitbox();
		bool collisionCheck(Vector2 p);
		void move(Vector2 destPos);
	};
}

