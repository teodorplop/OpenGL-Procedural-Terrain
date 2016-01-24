#pragma once

#include <vector>
#include "GameObject.h"
#include "Terrain\Terrain.h"

#include "Camera.h"
#include "Stuff/CameraController.h"
#include "RawModel.h"
#include "Shader.h"
#include "Texture.h"
#include "TexturedModel.h"
#include "Materials\Material.h"

#include "Core/Renderer.h"
#include "Terrain\TerrainRenderer.h"

class Scene {
private:
	Camera* camera;
	CameraController* cameraController;

	RawModel* objModel;
	TexturedModel* texturedObjModel;

	Texture* texture;
	Texture* terrainTexture;
	DirectionalLight* directionalLight;
	Material* material;

	std::vector<GameObject*> objects;
	std::vector<Terrain*> terrains;
	Shader* shader;
	Renderer* renderer;
	Shader* terrainShader;
	TerrainRenderer* terrainRenderer;

public:
	Scene();
	~Scene();
	void Draw();
};