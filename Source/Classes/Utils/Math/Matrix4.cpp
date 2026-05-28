#include "Matrix4.h"
#include "math_3d.h"
#include <cstdio>

Matrix4::Matrix4() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			elements[i][j] = 0.0f;
		}
	}
}

Matrix4::Matrix4(float diagonal) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			elements[i][j] = (i == j) ? diagonal : 0.0f;
		}
	}
}

void Matrix4::ApplyTranslation(Matrix4& matrix, const Vector3& translation) {
	matrix = matrix.Multiply(Matrix4::Translation(translation));
}
void Matrix4::ApplyScaling(Matrix4& matrix, const Vector3& scaling) {
	matrix = matrix.Multiply(Matrix4::Scaling(scaling));
}
void Matrix4::ApplyRotation(Matrix4& matrix, float angle, const Vector3& axis) {
	matrix = matrix.Multiply(Matrix4::Rotation(angle, axis));
}

Matrix4 Matrix4::Translation(const Vector3& translation) {
	Matrix4 result(1.0f);
	result.elements[0][3] = translation.x;
	result.elements[1][3] = translation.y;
	result.elements[2][3] = translation.z;

	return result;
}

Matrix4 Matrix4::Scaling(const Vector3& scale) {
	Matrix4 result(1.0f);
	result.elements[0][0] = scale.x;
	result.elements[1][1] = scale.y;
	result.elements[2][2] = scale.z;

	return result;
}

Matrix4 Matrix4::Rotation(float angle, Vector3 axis) {
	Matrix4 result(1.0f);
	angle = ToRadians(angle);

	float c = cos(angle);
	float s = sin(angle);
	float omc = 1.0f - c;

	float x = axis.x, y = axis.y, z = axis.z;

	result.elements[0][0] = c + x * x * omc;
	result.elements[0][1] = x * y * omc - z * s;
	result.elements[0][2] = x * z * omc + y * s;

	result.elements[1][0] = x * y * omc + z * s;
	result.elements[1][1] = c + y * y * omc;
	result.elements[1][2] = y * z * omc - x * s;

	result.elements[2][0] = x * z * omc - y * s;
	result.elements[2][1] = y * z * omc + x * s;
	result.elements[2][2] = c + z * z * omc;

	return result;
}

Matrix4 Matrix4::Orthographic(float left, float right, float bottom, float top, float nearClip, float farClip) {
	Matrix4 result(1.0f);

	result.elements[0][0] = 2.0f / (right - left);
	result.elements[1][1] = 2.0f / (top - bottom);
	result.elements[2][2] = 2.0f / (nearClip - farClip);

	result.elements[0][3] = (left + right) / (left - right);
	result.elements[1][3] = (bottom + top) / (bottom - top);
	result.elements[2][3] = (farClip + nearClip) / (farClip - nearClip);

	return result;
}

Matrix4 Matrix4::Perspective(float fieldOfView, float aspectRatio, float nearClip, float farClip) {
	Matrix4 result(1.0f);

	float t = tan(ToRadians(0.5f * fieldOfView));
	result.elements[0][0] = 1.0f / (aspectRatio * t);
	result.elements[1][1] = 1.0f / t;
	result.elements[2][2] = (-nearClip - farClip) / (nearClip - farClip);
	result.elements[2][3] = (2.0f * farClip * nearClip) / (nearClip - farClip);
	result.elements[3][2] = 1.0f;

	return result;
}

Matrix4& Matrix4::Invert() {
	float temp[4][4];

	temp[0][0] = elements[1][1] * elements[2][2] * elements[3][3] -
		elements[1][1] * elements[2][3] * elements[3][2] -
		elements[2][1] * elements[1][2] * elements[3][3] +
		elements[2][1] * elements[1][3] * elements[3][2] +
		elements[3][1] * elements[1][2] * elements[2][3] -
		elements[3][1] * elements[1][3] * elements[2][2];

	temp[1][0] = -elements[1][0] * elements[2][2] * elements[3][3] +
		elements[1][0] * elements[2][3] * elements[3][2] +
		elements[2][0] * elements[1][2] * elements[3][3] -
		elements[2][0] * elements[1][3] * elements[3][2] -
		elements[3][0] * elements[1][2] * elements[2][3] +
		elements[3][0] * elements[1][3] * elements[2][2];

	temp[2][0] = elements[1][0] * elements[2][1] * elements[3][3] -
		elements[1][0] * elements[2][3] * elements[3][1] -
		elements[2][0] * elements[1][1] * elements[3][3] +
		elements[2][0] * elements[1][3] * elements[3][1] +
		elements[3][0] * elements[1][1] * elements[2][3] -
		elements[3][0] * elements[1][3] * elements[2][1];

	temp[3][0] = -elements[1][0] * elements[2][1] * elements[3][2] +
		elements[1][0] * elements[2][2] * elements[3][1] +
		elements[2][0] * elements[1][1] * elements[3][2] -
		elements[2][0] * elements[1][2] * elements[3][1] -
		elements[3][0] * elements[1][1] * elements[2][2] +
		elements[3][0] * elements[1][2] * elements[2][1];

	temp[0][1] = -elements[0][1] * elements[2][2] * elements[3][3] +
		elements[0][1] * elements[2][3] * elements[3][2] +
		elements[2][1] * elements[0][2] * elements[3][3] -
		elements[2][1] * elements[0][3] * elements[3][2] -
		elements[3][1] * elements[0][2] * elements[2][3] +
		elements[3][1] * elements[0][3] * elements[2][2];

	temp[1][1] = elements[0][0] * elements[2][2] * elements[3][3] -
		elements[0][0] * elements[2][3] * elements[3][2] -
		elements[2][0] * elements[0][2] * elements[3][3] +
		elements[2][0] * elements[0][3] * elements[3][2] +
		elements[3][0] * elements[0][2] * elements[2][3] -
		elements[3][0] * elements[0][3] * elements[2][2];

	temp[2][1] = -elements[0][0] * elements[2][1] * elements[3][3] +
		elements[0][0] * elements[2][3] * elements[3][1] +
		elements[2][0] * elements[0][1] * elements[3][3] -
		elements[2][0] * elements[0][3] * elements[3][1] -
		elements[3][0] * elements[0][1] * elements[2][3] +
		elements[3][0] * elements[0][3] * elements[2][1];

	temp[3][1] = elements[0][0] * elements[2][1] * elements[3][2] -
		elements[0][0] * elements[2][2] * elements[3][1] -
		elements[2][0] * elements[0][1] * elements[3][2] +
		elements[2][0] * elements[0][2] * elements[3][1] +
		elements[3][0] * elements[0][1] * elements[2][2] -
		elements[3][0] * elements[0][2] * elements[2][1];

	temp[0][2] = elements[0][1] * elements[1][2] * elements[3][3] -
		elements[0][1] * elements[1][3] * elements[3][2] -
		elements[1][1] * elements[0][2] * elements[3][3] +
		elements[1][1] * elements[0][3] * elements[3][2] +
		elements[3][1] * elements[0][2] * elements[1][3] -
		elements[3][1] * elements[0][3] * elements[1][2];
	
	temp[1][2] = -elements[0][0] * elements[1][2] * elements[3][3] +
		elements[0][0] * elements[1][3] * elements[3][2] +
		elements[1][0] * elements[0][2] * elements[3][3] -
		elements[1][0] * elements[0][3] * elements[3][2] -
		elements[3][0] * elements[0][2] * elements[1][3] +
		elements[3][0] * elements[0][3] * elements[1][2];

	temp[2][2] = elements[0][0] * elements[1][1] * elements[3][3] -
		elements[0][0] * elements[1][3] * elements[3][1] -
		elements[1][0] * elements[0][1] * elements[3][3] +
		elements[1][0] * elements[0][3] * elements[3][1] +
		elements[3][0] * elements[0][1] * elements[1][3] -
		elements[3][0] * elements[0][3] * elements[1][1];

	temp[3][2] = -elements[0][0] * elements[1][1] * elements[3][2] +
		elements[0][0] * elements[1][2] * elements[3][1] +
		elements[1][0] * elements[0][1] * elements[3][2] -
		elements[1][0] * elements[0][2] * elements[3][1] -
		elements[3][0] * elements[0][1] * elements[1][2] +
		elements[3][0] * elements[0][2] * elements[1][1];

	temp[0][3] = -elements[0][1] * elements[1][2] * elements[2][3] +
		elements[0][1] * elements[1][3] * elements[2][2] +
		elements[1][1] * elements[0][2] * elements[2][3] -
		elements[1][1] * elements[0][3] * elements[2][2] -
		elements[2][1] * elements[0][2] * elements[1][3] +
		elements[2][1] * elements[0][3] * elements[1][2];

	temp[1][3] = elements[0][0] * elements[1][2] * elements[2][3] -
		elements[0][0] * elements[1][3] * elements[2][2] -
		elements[1][0] * elements[0][2] * elements[2][3] +
		elements[1][0] * elements[0][3] * elements[2][2] +
		elements[2][0] * elements[0][2] * elements[1][3] -
		elements[2][0] * elements[0][3] * elements[1][2];

	temp[2][3] = -elements[0][0] * elements[1][1] * elements[2][3] +
		elements[0][0] * elements[1][3] * elements[2][1] +
		elements[1][0] * elements[0][1] * elements[2][3] -
		elements[1][0] * elements[0][3] * elements[2][1] -
		elements[2][0] * elements[0][1] * elements[1][3] +
		elements[2][0] * elements[0][3] * elements[1][1];

	temp[3][3] = elements[0][0] * elements[1][1] * elements[2][2] -
		elements[0][0] * elements[1][2] * elements[2][1] -
		elements[1][0] * elements[0][1] * elements[2][2] +
		elements[1][0] * elements[0][2] * elements[2][1] +
		elements[2][0] * elements[0][1] * elements[1][2] -
		elements[2][0] * elements[0][2] * elements[1][1];

	float determinant = elements[0][0] * temp[0][0] + elements[0][1] * temp[1][0] + elements[0][2] * temp[2][0] + elements[0][3] * temp[3][0];
	determinant = 1.0f / determinant;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			elements[i][j] = temp[i][j] * determinant;
		}
	}

	return *this;
}

Matrix4& Matrix4::Multiply(const Matrix4& other) {
	float data[4][4];
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			float sum = 0.0f;
			for (int k = 0; k < 4; ++k) {
				sum += elements[i][k] * other.elements[k][j];
			}

			data[i][j] = sum;
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			elements[i][j] = data[i][j];
		}
	}

	return *this;
}

Matrix4 operator*(Matrix4 left, const Matrix4& right) {
	return left.Multiply(right);
}

Matrix4& Matrix4::operator*=(const Matrix4& other) {
	return Multiply(other);
}