#include "Shaders.h"

Shaders* Shaders::instance = NULL;

Shaders::Shaders() {
}

Shaders::~Shaders() {
}

Shader* Shaders::GetShader(std::string name) {
	std::unordered_map<std::string, Shader*>::iterator it = shaders.find(name);
	if (it != shaders.end()) {
		return it->second;
	}

	Shader* shader = new Shader(("Shaders/" + name + ".vert").c_str(), ("Shaders/" + name + ".frag").c_str());
	shaders[name] = shader;

	return shader;
}

Shaders* Shaders::GetInstance() {
	if (instance == NULL) {
		instance = new Shaders();
	}
	return instance;
}