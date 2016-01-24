#include "Material.h"

Material::Material() {
}
Material::Material(float shineDamper, float reflectivity, bool fakeLightning) {
	this->shineDamper = shineDamper, this->reflectivity = reflectivity, this->fakeLightning = fakeLightning;
}
