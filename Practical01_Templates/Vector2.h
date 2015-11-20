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

};


#endif