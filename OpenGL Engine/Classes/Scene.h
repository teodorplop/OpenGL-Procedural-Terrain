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
#include "Color.h"
#include "Effects\Fog.h"
#include "Stuff\PlayerController.h"

class Scene {
private:
	Camera* camera;
	CameraController* cameraController;

	Color skyColor;
	Fog fog;

	Texture* treeTexture;
	RawModel* treeModel;
	TexturedModel* treeTexturedModel;

	Texture* tree2Texture;
	RawModel* tree2Model;
	TexturedModel* tree2TexturedModel;

	Texture* grassTexture;
	RawModel* grassModel;
	TexturedModel* grassTexturedModel;

	Texture* fernTexture;
	RawModel* fernModel;
	TexturedModel* fernTexturedModel;

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