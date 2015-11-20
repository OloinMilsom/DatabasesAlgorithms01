#ifndef MATRIX2_H
#define MATRIX2_H

#include "Vector2.h"

template <typename T> class Matrix2 {
public:
	// Data
	T m_11;
	T m_12;
	T m_21;
	T m_22;

	// Constructors
	Matrix2() {}
	Matrix2(T m11, T m12, T m21, T m22) : m_11(m11), m_12(m12), m_21(m21), m_22(m22) {  }

	// unary addition
	template <typename U>
	void operator+= (Matrix2<U> & const other) {
		m_11 += other.m_11;
		m_12 += other.m_12;
		m_21 += other.m_21;
		m_22 += other.m_22;
	}

	// binary addition
	template <typename U>
	Matrix2<T> operator+ ( Matrix2<U> & const other) {
		Matrix2<T> curr = *this;
		return Matrix2<T>(curr.m_11 + other.m_11,
						  curr.m_12 + other.m_12,
						  curr.m_21 + other.m_21,
						  curr.m_22 + other.m_22)
	}

	// unary multiplication
	template <typename U>
	void operator*= (Matrix2<U> & const other) {
		Matrix2<T> t(m_11 * other.m_11 + m_12 * other.m_21, m_11 * other.m_12 + m_12 * other.m_22,
			m_21 * other.m_11 + m_22 * other.m_21, m_21 * other.m_12 + m_22 * other.m_22);
		m_11 = t.m_11;
		m_12 = t.m_12;
		m_21 = t.m_21;
		m_22 = t.m_22;
	}

	// binary multiplication
	template <typename U>
	Matrix2<T> operator* (Matrix2<U> & const other) {
		Matrix2<T> curr = *this;
		return Matrix2<T>(curr.m_11 * other.m_11 + curr.m_12 * other.m_21,
						  curr.m_11 * other.m_12 + curr.m_12 * other.m_22,
						  curr.m_21 * other.m_11 + curr.m_22 * other.m_21,
						  curr.m_21 * other.m_12 + curr.m_22 * other.m_22);
	}

	// multiplication with a vector
	template <typename U>
	Vector2<U> operator* (Vector2<U> & const v) {
		return Vector2<U>(m_11 * v.x + m_12 * v.y, m_21 * v.x + m_22 * v.y);
	}

	template <typename U>
	static Matrix2<double> rotate(U angle){
		return Matrix2<double>(std::cos(angle), -std::sin(angle), std::sin(angle), std::cos(angle));
	}
};

#endif