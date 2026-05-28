#pragma once

#include "../Shader.h"
#include "../Camera.h"
#include "../RawModel.h"
#include "../TexturedModel.h"
#include "WaterFrameBuffer.h"
#include "Water.h"
#include <vector>

class WaterRenderer {
private:
	static const float moveSpeed;
	float moveFactor;

	Shader* shader;
	Camera* camera;

	WaterFrameBuffer* waterFrameBuffer;
	Texture* dudvTexture;

	void EnableCulling(bool enabled);

public:
	WaterRenderer(Shader* shader, Camera* camera, WaterFrameBuffer* waterFrameBuffer);
	void Draw(const std::vector<Water*>& waters);
};