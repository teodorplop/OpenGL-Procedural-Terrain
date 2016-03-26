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
#include "Water\Water.h"
#include "Interface\UITexture.h"

#include "Core/Renderer.h"
#include "Terrain\TerrainRenderer.h"
#include "Water\WaterRenderer.h"
#include "Interface\UIRenderer.h"

#include "Color.h"
#include "Effects\Fog.h"

#include "Water\WaterFrameBuffer.h"

class Scene {
private:
	Camera* camera;
	CameraController* cameraController;

	Color skyColor;
	Fog fog;
	DirectionalLight* directionalLight;

	std::vector<Terrain*> terrains;
	Material* terrainMaterial;
	Shader* terrainShader;
	TerrainRenderer* terrainRenderer;

	std::vector<Water*> waters;
	Material* waterMaterial;
	Shader* waterShader;
	WaterRenderer* waterRenderer;

	std::vector<UITexture*> uiTextures;
	Shader* uiShader;
	UIRenderer* uiRenderer;

	WaterFrameBuffer* waterFrameBuffer;

public:
	Scene();
	~Scene();
	void Draw();
};