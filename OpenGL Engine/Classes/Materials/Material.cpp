#include "Material.h"

Material::Material() {
}
Material::Material(float shineDamper, float reflectivity) {
	this->shineDamper = shineDamper, this->reflectivity = reflectivity;
}
