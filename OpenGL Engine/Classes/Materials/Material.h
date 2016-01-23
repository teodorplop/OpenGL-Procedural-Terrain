#pragma once

struct Material {
	float shineDamper;
	float reflectivity;

	Material();
	Material(float shineDamper, float reflectivity);
};

