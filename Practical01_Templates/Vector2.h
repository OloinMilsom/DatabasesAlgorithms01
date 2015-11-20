#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

template <typename T> class Vector2 {
public:
	// Data
	T x;
	T y;

	// Constructors
	Vector2(){}
	Vector2(T _x, T _y) : x (_x), y(_y){}

	// unary addition
	template <typename U>
	void operator+= (Vector2<U> & const other) {
		x += other.x;
		y += other.y;
	}

	// binary addition
	template <typename U>
	Vector2<T> operator+ (Vector2<U> & const other) {
		return Vector2<T>(x + other.x, y + other.y)
	}

	// unary multiplication with a scalar
	template <typename U>
	void operator*= (U const scalar) {
		x *= scalar;
		y *= scalar;
	}

	// binary multiplication with a scalar
	template <typename U>
	Vector2<T> operator* (U const scalar) {
		return Vector2<T>(x * scalar, y * scalar);
	}

	// assignment
	template <typename U>
	Vector2<T> operator= (Vector2<U> & const other) {
		x = other.x;
		y = other.y;
		return *this;
	}
};


#endif