#include "math.h"

namespace ChoccoEngine {
	/**
	* fast Square root algorythm
	* goes through this while loop until result is close enough to the actual value
	* the variable maxDiff can be
	**/
	double fastSqrt(double a) {
		double maxDiff = 0.01, result = a / 2;
		while (abs(result * result - a) > maxDiff) {
			result -= (((result * result) - a) / (2 * result));
		}
		return result;
	}

	double pythagoras(Vector2 a, Vector2 b) {
		double x = b.x - a.x, y = b.y - a.y, result;
		result = fastSqrt(x * x + y * y);
		return result;
	}

	double deltatime() {
		uint64_t now = SDL_GetPerformanceCounter();
		double deltatime = double(now/SDL_GetPerformanceFrequency());
		return deltatime;
	}

// Vector class
	Vector2::Vector2() : x(0), y(0) { }

	Vector2::Vector2(double x, double y) : x(x), y(y) { }

	// this can make changing the values in the vector a bit easier

	Vector2 Vector2::operator*(double a) {
		return Vector2(x * a, y * a);
	}

	Vector2 Vector2::operator*(Vector2 a) {
		return Vector2(x * a.x + x * a.y, y * a.x + y * a.y);
	}

	Vector2 Vector2::operator/(double a) {
		return Vector2(x / a, y / a);
	}

	Vector2 Vector2::operator+(Vector2 a) {
		return Vector2(a.x + x, a.y + y);
	}

	Vector2 Vector2::operator-(Vector2 a) {
		return Vector2(a.x - x, a.y - y);
	}

	void Vector2::operator*=(double a) {
		x *= a;
		y *= a;
	}

	void Vector2::operator*=(Vector2 a) {
		x *= (a.x + a.y);
		y *= (a.x + a.y);
	}

	void Vector2::operator/=(double a) {
		x /= a;
		y /= a;
	}


	void Vector2::operator+=(Vector2 a) {
		x += a.x;
		y += a.y;
	}


	void Vector2::operator-=(Vector2 a) {
		x -= a.x;
		y -= a.y;
	}


	// normalizing vectors
	void Vector2::normalize() {
		double v = fastSqrt(x * x + y * y);
		Vector2(x, y) / v;
	}
}
