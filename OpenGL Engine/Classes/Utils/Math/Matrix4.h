#ifndef __MATRIX_4_H__
#define __MATRIX_4_H__

#include "Vector3.h"

struct Matrix4 {
	float elements[4][4];

	Matrix4();
	Matrix4(float diagonal);

	static void ApplyTranslation(Matrix4& matrix, const Vector3& translation);
	static void ApplyScaling(Matrix4& matrix, const Vector3& scaling);
	static void ApplyRotation(Matrix4& matrix, float angle, const Vector3& axis);

	static Matrix4 Translation(const Vector3& translation);
	static Matrix4 Scaling(const Vector3& scale);
	static Matrix4 Rotation(float angle, Vector3 axis);

	static Matrix4 Orthographic(float left, float right, float bottom, float top, float nearClip, float farClip);
	static Matrix4 Perspective(float fieldOfView, float aspectRatio, float nearClip, float farClip);

	Matrix4& Invert();
	Matrix4& Multiply(const Matrix4& other);
	friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
	Matrix4& operator*=(const Matrix4& other);
};

#endif // __MATRIX_4_H__