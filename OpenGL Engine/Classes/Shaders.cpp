#include "Shaders.h"

Shaders* Shaders::instance = NULL;

Shaders::Shaders() {
	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
}

Shaders::~Shaders() {
}

void Shaders::Init() {
	if (instance == NULL) {
		instance = new Shaders();
	}
}

Shaders* Shaders::GetInstance() {
	if (instance == NULL) {
		Init();
	}
	return instance;
}