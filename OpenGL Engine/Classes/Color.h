#pragma once

class Color {
public:
	float r, g, b, a;
	Color();
	Color(float r, float g, float b, float a);

	const static Color red, blue, green, yellow, white;

	bool operator==(const Color& other);
};