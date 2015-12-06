#ifndef __MATRIX_4_H__
#define __MATRIX_4_H__

#include "Vector3.h"

struct Matrix4 {
	float elements[4][4];

	Matrix4();
	Matrix4(float diagonal);

	static Matrix4 Translation(const Vector3& translation);
	static Matrix4 Scale(const Vector3& scale);
	static Matrix4 Rotation(float angle, Vector3 axis);

	Matrix4& Multiply(const Matrix4& other);
	friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
	Matrix4& operator*=(const Matrix4& other);
};

#endif // __MATRIX_4_H__