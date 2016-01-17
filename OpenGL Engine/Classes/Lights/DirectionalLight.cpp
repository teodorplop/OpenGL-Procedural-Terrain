#include "DirectionalLight.h"

DirectionalLight::DirectionalLight() {
	color = Color::white, ambientIntensity = 1.0f, direction = Vector3(), diffuseIntensity = 1.0f;
}

DirectionalLight::DirectionalLight(Color color, float intensity, Vector3 direction, float diffuseIntensity) {
	this->color = color, this->ambientIntensity = intensity, this->direction = direction, this->diffuseIntensity = diffuseIntensity;
}

DirectionalLight::~DirectionalLight() {
}
