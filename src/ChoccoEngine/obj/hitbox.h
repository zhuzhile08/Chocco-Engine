#pragma once

#include "../Util/math.h"

namespace ChoccoEngine {
	class LineHitbox {
	private:
		Vector2f a, b, c, position;
	public:
		LineHitbox(Vector2f a, Vector2f b, Vector2f position);
		~LineHitbox();
		bool collisionCheck(Vector2f p);
		void move(Vector2f destPos);
	};

	class RectHitbox {
	private:
		Vector2f a, b, c, d, position;
	public:
		RectHitbox(Vector2f a, Vector2f b, Vector2f position);
		~RectHitbox();
		bool collisionCheck(Vector2f p);
		void move(Vector2f destPos);
	};

	class CircleHitbox {
	private:
		double radius;
		Vector2f position;
	public:
		CircleHitbox(double radius, Vector2f position);
		~CircleHitbox();
		bool collisionCheck(Vector2f p);
		void move(Vector2f destPos);
	};
}

