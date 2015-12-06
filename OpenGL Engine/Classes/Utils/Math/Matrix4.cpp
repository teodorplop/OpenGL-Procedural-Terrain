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

Matrix4 Matrix4::Translation(const Vector3& translation) {
	Matrix4 result(1.0f);
	result.elements[0][3] = translation.x;
	result.elements[1][3] = translation.y;
	result.elements[2][3] = translation.z;

	return result;
}

Matrix4 Matrix4::Scale(const Vector3& scale) {
	Matrix4 result(1.0f);
	result.elements[0][0] = scale.x;
	result.elements[1][1] = scale.y;
	result.elements[2][2] = scale.z;

	return result;
}

Matrix4 Matrix4::Rotation(float angle, char axis = 'Z') {
	Matrix4 result(1.0f);
	angle = ToRadians(angle);

	float c = cos(angle);
	float s = sin(angle);

	if (axis == 'z' || axis == 'Z') {
		result.elements[0][0] = c;
		result.elements[0][1] = -s;
		result.elements[1][0] = s;
		result.elements[1][1] = c;
	} else if (axis == 'y' || axis == 'Y') {
		result.elements[0][0] = c;
		result.elements[0][2] = -s;
		result.elements[2][0] = s;
		result.elements[2][2] = c;
	}	else if (axis == 'x' || axis == 'X') {
		result.elements[1][1] = c;
		result.elements[1][2] = -s;
		result.elements[2][1] = s;
		result.elements[2][2] = c;
	}	else {
		fprintf(stderr, "Invalid axis rotation.");
	}

	return result;
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