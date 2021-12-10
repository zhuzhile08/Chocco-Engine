#include <ChoccoEngine/Cmath.h>

namespace chocco {
	// fast square root algorythm
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

	// functions for the vector class

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

	// some math functions

	double FPS() {
		return 1000/SDL_GetTicks();
	}

	double sigmoid(double x) {
		return 1/(1+pow(EULER, x));
	}

	void sigmoidMod(double num, double result, double time) { // this is basicly a function for non-linear interpolation of a number using a modified sigmoid fuction
		double originalNum = num, constant = 6 / time * 1000 * result, currentX = -6;

		while (currentX != 6) {
			num = originalNum + sigmoid(currentX);
			currentX += constant/FPS();
		}
	}

	double randDoub(double x, double y, int precision) {
		return double(rand() % precision) * (y - x)/precision;
	}
}
