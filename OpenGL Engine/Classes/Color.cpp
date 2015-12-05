#include "Color.h"

const Color Color::red = Color(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::blue = Color(0.0f, 0.0f, 1.0f, 1.0f);

Color::Color(float r, float g, float b, float a = 1.0f) {
	this->r = r, this->g = g, this->b = b, this->a = a;
}