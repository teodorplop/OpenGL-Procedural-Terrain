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

	Texture* terrainTexture;

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

private:
	bool dirty;
	int terrainSeed;
	int terrainOctaves;
	int heightMapResolution;
	bool waterEnabled;
	void ClearWater();
	void ClearTerrain();
	void RefreshTerrain();

public:
	Scene();
	~Scene();
	void Draw();
	void Update();

	// Console functions
	void SetSeed(int seed);
	void SetHeightMapRes(int res);
	void SetOctaves(int octaves);
	void SetTerrainSize(float size);
	void SetTerrainHeight(float height);
	void SetWater(bool enabled);
	void SetSmooth(float smooth);
	void SetPersistence(int persistence);
};