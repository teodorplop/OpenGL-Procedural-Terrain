#include "Vector2.h"

Vector2::Vector2() {
	x = y = 0.0;
}
Vector2::Vector2(float x, float y) {
	this->x = x, this->y = y;
}

std::ostream& operator<<(std::ostream& out, const Vector2& data) {
	out << data.x << " " << data.y << "\n";
	return out;
}