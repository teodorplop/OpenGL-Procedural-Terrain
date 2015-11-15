#ifndef __MATRIX_4_H__
#define __MATRIX_4_H__

#include "Vector3.h"

struct Matrix4 {
	float elements[4][4];

	Matrix4();
	Matrix4(float diagonal);

	static Matrix4 Translation(const Vector3& translation);
	static Matrix4 Scale(const Vector3& scale);
	static Matrix4 Rotation(float angle, char axis);
};

#endif // __MATRIX_4_H__