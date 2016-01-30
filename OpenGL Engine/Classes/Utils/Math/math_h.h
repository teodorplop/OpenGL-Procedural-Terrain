#pragma once

#define M_PI 3.14159265359f
#include "Vector2.h"
#include "Vector3.h"

float ToRadians(float angle);
float Clamp(float value, float left, float right);
float GetYCoord(const Vector3& a, const Vector3& b, const Vector3& c, const float& x, const float& z);