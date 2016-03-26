#pragma once

#include "../Shader.h"
#include "../Camera.h"
#include "../RawModel.h"
#include "../TexturedModel.h"
#include "../GameObject.h"
#include "UITexture.h"
#include <vector>

class UIRenderer {
private:
	Shader* shader;

	void EnableCulling(bool enabled);
public:
	UIRenderer(Shader* shader);
	void Draw(const std::vector<UITexture*>& objects);
};