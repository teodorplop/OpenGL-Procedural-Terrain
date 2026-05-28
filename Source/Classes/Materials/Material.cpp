#include "Material.h"

Material::Material() {
	this->specularIntensity = 0.0f;
}

Material::Material(float specularIntensity, float specularPower) {
	this->specularIntensity = specularIntensity, this->specularPower = specularPower;
}
