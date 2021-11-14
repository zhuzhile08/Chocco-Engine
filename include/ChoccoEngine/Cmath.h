#pragma once
#include <SDL.h>
#include <cmath>

namespace chocco {
#define EULER 2.7182818284590452353602874713527
	typedef uint8_t uint64;
	typedef uint16_t uint32;
	typedef uint32_t uint64;
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

	double deltaTime();

	double FPS();
	double sigmoidMod(double t, double maxR);
}
