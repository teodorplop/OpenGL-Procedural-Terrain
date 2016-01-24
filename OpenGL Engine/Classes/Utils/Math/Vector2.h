#pragma once

#include<iostream>

struct Vector2 {
	float x, y;
	Vector2();
	Vector2(float x, float y);

	friend std::ostream& operator<<(std::ostream& out, const Vector2& data);
};

