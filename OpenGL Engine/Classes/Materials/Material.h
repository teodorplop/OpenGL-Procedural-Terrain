#pragma once

struct Material {
	float specularIntensity;
	float specularPower;

	Material();
	Material(float specularIntensity, float specularPower);
};

