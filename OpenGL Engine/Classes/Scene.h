#pragma once

#include <vector>
#include "GameObject.h"

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

	RawModel* objModel;
	TexturedModel* texturedObjModel;

	Texture* texture;
	Shader* shader;
	DirectionalLight* directionalLight;
	Material* material;

	std::vector<GameObject*> objects;

public:
	Scene();
	~Scene();
	void Draw();
};