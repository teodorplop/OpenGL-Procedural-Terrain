#pragma once

#include "../Shader.h"
#include "../Camera.h"
#include "../RawModel.h"
#include "../TexturedModel.h"
#include "Terrain.h"
#include <vector>

#include "../GameObject.h"

class TerrainRenderer {
private:
	Shader* shader;
	Camera* camera;

public:
	TerrainRenderer(Shader* shader, Camera* camera);
	void Draw(const std::vector<Terrain*>& terrains);
};