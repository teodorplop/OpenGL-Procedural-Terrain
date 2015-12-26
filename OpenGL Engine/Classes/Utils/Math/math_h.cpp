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