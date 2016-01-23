#pragma once

#include "Camera.h"
#include "Stuff/CameraController.h"
#include "RawModel.h"
#include "Shader.h"
#include "Texture.h"
#include "TexturedModel.h"

class Scene {
private:
	Camera* camera;
	CameraController* cameraController;

	RawModel* model;
	TexturedModel* texturedModel;
	Texture* texture;
	Shader* shader;

	RawModel* objModel;
	TexturedModel* texturedObjModel;

public:
	Scene();
	~Scene();
	void Draw();
};