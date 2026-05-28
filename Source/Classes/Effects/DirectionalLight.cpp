#include "DirectionalLight.h"

DirectionalLight::DirectionalLight() {
	color = Color::white, ambientIntensity = 0.75f, direction = Vector3(1.0f, -1.0f), diffuseIntensity = 0.75f;
}

DirectionalLight::DirectionalLight(Color color, float intensity, Vector3 direction, float diffuseIntensity) {
	this->color = color, this->ambientIntensity = intensity, this->direction = direction, this->diffuseIntensity = diffuseIntensity;
}
