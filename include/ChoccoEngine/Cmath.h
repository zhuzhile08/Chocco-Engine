#pragma once

#include <SDL.h>
#include <cmath>
#include <cstdlib>

/**
 * math file
 * some definitions, math operations and a 2d vector struct
 * there is also a function calculating the FPS and some sigmoid stuff for animations
**/

namespace chocco {
#define EULER 2.718281828459045
#define PI 3.141592653589793
#define GOLDENR 1.618033988749894

	typedef uint8_t uint8;
	typedef uint16_t uint16;
	typedef uint32_t uint32;
	typedef uint64_t uint64;

	typedef int8_t int8;
	typedef int16_t int16;
	typedef int32_t int32;
	typedef int64_t int64;
	
	// Vectors
	struct Vector2 {
		double x, y;
		Vector2(); 
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
	void sigmoidMod(double t, double maxR);
	double randDoub(double x, double y, int precision);

	double FPS();
}
