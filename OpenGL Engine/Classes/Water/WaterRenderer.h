#pragma once

#include "../Shader.h"
#include "../Camera.h"
#include "../RawModel.h"
#include "../TexturedModel.h"
#include "Water.h"
#include <vector>

class WaterRenderer {
private:
	Shader* shader;
	Camera* camera;

	void EnableCulling(bool enabled);

public:
	WaterRenderer(Shader* shader, Camera* camera);
	void Draw(const std::vector<Water*>& waters);
};