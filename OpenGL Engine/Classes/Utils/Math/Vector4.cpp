#include "Vector4.h"

Vector4::Vector4() {
	x = y = z = 0.0f;
	w = 1.0f;
}
Vector4::Vector4(float x, float y, float z, float w) {
	this->x = x, this->y = y, this->z = z, this->w = w;
}