#pragma once
#include <iostream>
#include "SDL.h"

namespace ChoccoEngine {
	// Vectors
	struct Vector2 {
	public:
		double x, y;
		Vector2(double x, double y);

		Vector2 operator*(double a); Vector2 operator*(Vector2 a);
		Vector2 operator/(double a);
		Vector2 operator+(Vector2 a);
		Vector2 operator-(Vector2 a);

		void operator*=(double a); void operator*=(Vector2 a);
		void operator/=(double a);
		void operator+=(Vector2 a);
		void operator-=(Vector2 a);

		void normalize();
	};

	// math operations
	double fastSqrt(double a);
	double pythagoras(Vector2 a, Vector2 b);

	double deltaTime();
}
