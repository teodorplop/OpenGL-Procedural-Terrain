#include "Color.h"

const Color Color::red = Color(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::blue = Color(0.0f, 0.0f, 1.0f, 1.0f);
const Color Color::green = Color(0.0f, 1.0f, 0.0f, 1.0f);
const Color Color::yellow = Color(1.0f, 1.0f, 0.0f, 1.0f);
const Color Color::white = Color(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::grey = Color(0.5f, 0.5f, 0.5f, 1.0f);
const Color Color::sky = Color(0.815f, 0.925f, 0.992f, 1.0f);

Color::Color() {
	this->r = this->g = this->b = this->a = 1.0f;
}

Color::Color(float r, float g, float b, float a = 1.0f) {
	this->r = r, this->g = g, this->b = b, this->a = a;
}

Vector3 Color::ToVector3() const {
	return Vector3(this->r, this->g, this->b);
}
Vector4 Color::ToVector4() const {
	return Vector4(this->r, this->g, this->b, this->a);
}

bool Color::operator==(const Color& other) {
	return r == other.r && g == other.g && b == other.b && a == other.a;
}