#pragma once

#include "Utils\Math\Vector3.h"
#include "Utils\Math\Vector4.h"

class Color {
public:
	float r, g, b, a;
	Color();
	Color(float r, float g, float b, float a);
	Vector3 ToVector3() const;
	Vector4 ToVector4() const;

	const static Color red, blue, green, yellow, white, grey;

	bool operator==(const Color& other);
};