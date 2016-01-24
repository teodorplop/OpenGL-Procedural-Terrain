#pragma once

#include<iostream>

struct Vector4 {
	float x, y, z, w;
	Vector4();
	Vector4(float x, float y, float z, float w = 1.0f);

	friend std::ostream& operator<<(std::ostream& out, const Vector4& data);
};

