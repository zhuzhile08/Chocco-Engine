#pragma once

#include "Cmath.h"

namespace chocco {
	class PolygonHitbox {
	private:
		Vector2 a, b, c, position;
	public:
		PolygonHitbox(Vector2 a, Vector2 b, Vector2 c,  Vector2 position);
		~PolygonHitbox();
		bool collisionCheck(Vector2 p);
		void move(Vector2 destPos);
	};

	class RectHitbox {
	private:
		Vector2 a, b, c, d, position;
	public:
		RectHitbox(Vector2 a, Vector2 b, Vector2 position);
		~RectHitbox();
		bool collisionCheck(Vector2 p);
		void move(Vector2 destPos);
	};

	class CircleHitbox {
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

