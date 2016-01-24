#include "Fog.h"

Fog::Fog() {
	this->density = 0.0035f, this->gradient = 5.0f;
}
Fog::Fog(float density, float gradient) {
	this->density = density, this->gradient = gradient;
}
