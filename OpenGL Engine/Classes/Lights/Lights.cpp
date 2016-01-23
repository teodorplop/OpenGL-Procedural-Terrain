#include "Lights.h"

DirectionalLight Lights::directionalLight;

Lights::Lights() {
}

Lights::~Lights() {
}

void Lights::AddLight(const DirectionalLight& light) {
	directionalLight = light;
}
DirectionalLight Lights::GetDirectionalLight() {
	return directionalLight;
}