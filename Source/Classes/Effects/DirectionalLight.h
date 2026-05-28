#pragma once

#include "../Color.h"
#include "../Utils/Math/Vector3.h"

struct DirectionalLight {
	Color color;
	float ambientIntensity;
	Vector3 direction;
	float diffuseIntensity;

	DirectionalLight();
	DirectionalLight(Color color, float intensity, Vector3 direction, float diffuseIntensity);
};
