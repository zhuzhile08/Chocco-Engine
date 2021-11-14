#include <ChoccoEngine/Cmath.h>

namespace chocco {
	/**
	* fast Square root algorythm
	* goes through this while loop until result is close enough to the actual value
	* the variable maxDiff can be
	**/
	double fastSqrt(double a) {
		double maxDiff = 0.01, result = a / 2;
		while (fabs(result * result - a) > maxDiff) {
			result -= (((result * result) - a) / (2 * result));
		}
		return result;
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

	void Vector2::normalize() {
		double v = fastSqrt(x * x + y * y);
		Vector2(x, y) / v;
	}

	double pythagoras(Vector2 a, Vector2 b) {
		double x = b.x - a.x, y = b.y - a.y, result;
		result = fastSqrt(x * x + y * y);
		return result;
	}

	double FPS() {
		return 1000/SDL_GetTicks();
	}

	double sigmoid(double x) {
		return 1/(1+pow(EULER, x));
	}

	double sigmoidMod(double t, double maxResult, double current) {
		return sigmoid(3-((6/current*maxResult))) * maxResult;
	}
}
