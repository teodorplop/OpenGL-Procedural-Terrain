#pragma once

#include "../Shader.h"
#include "../Camera.h"
#include "../GameObject.h"
#include "../RawModel.h"
#include "../TexturedModel.h"
#include <vector>

class Renderer {
private:
	Shader* shader;
	Camera* camera;

	void EnableCulling(bool enabled);
public:
	Renderer(Shader* shader, Camera* camera);
	void Draw(const std::vector<GameObject*>& objects, Vector4 clipPlane);
};
