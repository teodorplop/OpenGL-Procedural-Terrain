#include "math_h.h"
#include <algorithm>

float ToRadians(float angle) {
	return angle * 3.14159265359f / 180.0f;
}

float Clamp(float value, float left, float right) {
	value = std::max(value, left);
	value = std::min(value, right);
	return value;
}

float GetYCoord(const Vector3& p1, const Vector3& p2, const Vector3& p3, const float& x, const float& z) {
	Vector3 p1p2 = p2 - p1, p1p3 = p3 - p1;
	Vector3 p1p2Xp1p3 = Vector3::CrossProduct(p1p2, p1p3);
	float a = p1p2Xp1p3.x, b = p1p2Xp1p3.y, c = p1p2Xp1p3.z;
	float d = -(a * p1.x + b * p1.y + c * p1.z);

	return -(a * x + c * z + d) / b;
}