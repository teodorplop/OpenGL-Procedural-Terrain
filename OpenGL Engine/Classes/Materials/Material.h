#pragma once

struct Material {
	float shineDamper;
	float reflectivity;
	bool fakeLightning;

	Material();
	Material(float shineDamper, float reflectivity, bool fakeLightning);
};

