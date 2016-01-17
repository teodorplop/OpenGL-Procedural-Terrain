#pragma once

#include "Shader.h"
#include <unordered_map>

class Shaders {
private:
	static Shaders* instance;
	Shaders();
	~Shaders();

	std::unordered_map<std::string, Shader*> shaders;

public:
	Shader* GetShader(std::string name);
	static Shaders* GetInstance();
};