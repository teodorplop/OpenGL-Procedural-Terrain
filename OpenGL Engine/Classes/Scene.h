#pragma once

#include "Camera.h"
#include "Stuff/CameraController.h"
#include "RawModel.h"
#include "Shader.h"
#include "Texture.h"
#include "TexturedModel.h"
#include "Materials\Material.h"

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

	DirectionalLight* directionalLight;
	Material* material;

public:
	Scene();
	~Scene();
	void Draw();
};