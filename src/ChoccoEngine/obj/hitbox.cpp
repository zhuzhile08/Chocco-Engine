#include "hitbox.h"


namespace ChoccoEngine
{
	/** 
	* hitboxes
	*
	* Line Hitboxes (technically Triangle Colliders) can only be right angled
	* A hitbox consists of 3 variables: a, b, c (calculated). a and b HAVE TO be defined from BOTTOM TO TOP, else, the collision algorithm won't work.
	* it can only detect collision with single points
	* reccomended for only slopes
	* 
	*      B
	*     /|
	*    / |
	* A /__| C
	* 
	**/

	PolygonHitbox::PolygonHitbox(Vector2 a, Vector2 b, Vector2 c, Vector2 position) : a(a), b(b), c(c), position(position) { }

	bool PolygonHitbox::collisionCheck(Vector2 p) {
		double m1 = (a.x * (c.y - a.y) + (p.y * a.y) * (c.x - a.x) - p.x * (c.y - a.y)) / ((b.y - a.y) * (c.x - a.x) - (b.x - a.x) * (c.y - a.y));
		double m2 = (p.y - a.y - m1 * (b.y - a.y)) / (c.y - a.y);
		if (m1 >= 0 && m2 >= 0 && (m1 + m2) <= 1) return true;
		else return false;
	}

	void PolygonHitbox::move(Vector2 destPos) {
		position = destPos;
	}

	/**
	* Rectangle Hitbox consists of 4 points. defined are only the bottom left and the top right.
	* the definable edges HAVE TO be defined in the order bottom left and fop right.
	* they can only detect collision with single points, but that's all you need
	* reccomended for only tiles or sprites, that act like tiles
	* 
	* A        B
	*  ________
	* |        |
	* |        |
	* |________|
	* C        D
	* 
	**/

	RectHitbox::RectHitbox(Vector2 c, Vector2 b, Vector2 position) : a(b.x, c.y), b(b), c(c), d(c.x, b.y), position(position) { }

	bool RectHitbox::collisionCheck(Vector2 p) {
		if (p.x <= a.x || p.x >= b.x || p.y >= c.y || p.y <= a.y) return true;
		else return false;
	}

	void RectHitbox::move(Vector2 destPos) {
		position = destPos;
	}

	/**
	* Circle colliders. The only thing you have to define here is the radius. That's all
	* The simplest form of colliders. it's very quick and efficient, perfect for sprites.
	**/

	CircleHitbox::CircleHitbox(double radius, Vector2 position) : radius(radius), position(position) { }

	bool CircleHitbox::collisionCheck(Vector2 p) {
		if (pythagoras(position, p) == radius) return true;
		else return false;
	}

	void CircleHitbox::move(Vector2 destPos) {
		position = destPos;
	}
}
