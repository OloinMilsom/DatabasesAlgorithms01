#include <iostream>
#include "Vector2.h"
#include "Matrix2.h"


template <typename T, typename U>
void printRotations(Matrix2<T> matrix, Vector2<U> vector);

int main() {
	double pi = std::acos(-1);
	Vector2<int> vectorInt(1, 0);
	Vector2<float> vectorFloat(1.5, 2.5);
	Matrix2<int> matrixInt(0, -1, 1, 0);
	Matrix2<double> matrixDouble = Matrix2<double>::rotate(pi / 6);

	printRotations(matrixInt, vectorInt);
	printRotations(matrixDouble, vectorFloat);
	printRotations(matrixDouble * matrixInt, vectorFloat * 2);
	
	system("PAUSE");
}

template <typename T, typename U>
void printRotations(Matrix2<T> matrix, Vector2<U> vector){
	std::cout << "Rotation of a Vector:" << std::endl;
	std::cout << "\tRotation Matrix:" << std::endl;
	std::cout << "\t| " << matrix.m_11 << ", " << matrix.m_12 << " |" << std::endl;
	std::cout << "\t| " << matrix.m_21 << ", " << matrix.m_22 << " |" << std::endl;

	std::cout << "\tVector Before and After Rotation:" << std::endl;
	std::cout << "\t(" << vector.x << ", " << vector.y << ")" << std::endl;
	vector = matrix * vector;
	std::cout << "\t(" << vector.x << ", " << vector.y << ")" << std::endl << std::endl;
}



