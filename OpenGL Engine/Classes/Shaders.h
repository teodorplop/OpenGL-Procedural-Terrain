#pragma once

#include "Shader.h"

class Shaders {
private:
	static Shaders* instance;
	Shaders();
	~Shaders();

public:
	Shader* shader;
	static void Init();
	static Shaders* GetInstance();
};

