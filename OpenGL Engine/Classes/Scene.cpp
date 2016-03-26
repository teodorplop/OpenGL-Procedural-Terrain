#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"
#include "Terrain/HeightMapGenerator.h"

Scene::Scene() {
	Window* window = Window::GetWindow();
	int width = window->GetWidth(), height = window->GetHeight();

	camera = new Camera(Projection::Perspective, 45.0f, (float)width / height, 1.0f, 500.0f);
	cameraController = new CameraController(camera->GetTransform());
	camera->GetTransform()->TranslateTo(Vector3(0.0f, 10.0f, -10.0f));

	skyColor = Color::sky;
	glClearColor(skyColor.r, skyColor.g, skyColor.b, skyColor.a);
	fog = Fog();

	directionalLight = new DirectionalLight(Color::white, 0.25f, Vector3(-1.0f, -1.0f), 0.75f);

	// TERRAIN
	Texture* backgroundTexture = new Texture("Textures/Terrain/grass.png");
	Texture* rTexture = new Texture("Textures/Terrain/mud.png");
	Texture* gTexture = new Texture("Textures/Terrain/grassFlowers.png");
	Texture* bTexture = new Texture("Textures/Terrain/path.png");
	TerrainTexturePack* terrainTexturePack = new TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);
	Texture* blendMapTexture = new Texture("Textures/Terrain/blendMap.png");

	HeightMapGenerator::Generate("heightMap", 256, 256);
	Terrain* terrain = new Terrain(0, 0, terrainTexturePack, blendMapTexture, "Textures/Terrain/HeightMaps/heightMap.png");
	terrains.push_back(terrain);

	terrainMaterial = new Material(0.25f, 32.0f);
	terrainShader = new Shader("Shaders/TerrainShader.vert", "Shaders/TerrainShader.frag");
	terrainRenderer = new TerrainRenderer(terrainShader, camera);

	// WATER
	Water* water = new Water(0, 0);
	waters.push_back(water);

	waterMaterial = new Material(0.25f, 32.0f);
	waterShader = new Shader("Shaders/WaterShader.vert", "Shaders/WaterShader.frag");
	waterRenderer = new WaterRenderer(waterShader, camera);

	waterFrameBuffer = new WaterFrameBuffer();

	// UI
	UITexture* uiTexture = new UITexture(waterFrameBuffer->GetReflectionTexture());
	uiTexture->GetGameObject()->GetTransform()->ScaleTo(Vector3(0.5f, 0.5f, 1.0f));
	uiTexture->GetGameObject()->GetTransform()->TranslateTo(Vector3(-1.0f, 1.0f));
	uiTextures.push_back(uiTexture);

	uiShader = new Shader("Shaders/UIShader.vert", "Shaders/UIShader.frag");
	uiRenderer = new UIRenderer(uiShader);

	terrainShader->Bind();
	terrainShader->SetUniformDirectionalLight("directionalLight", *directionalLight);
	terrainShader->SetUniform1f("specularLight.materialIntensity", terrainMaterial->specularIntensity);
	terrainShader->SetUniform1f("specularLight.power", terrainMaterial->specularPower);
	terrainShader->SetUniform3f("skyColor", skyColor.ToVector3());
	terrainShader->SetUniform1f("fog.density", fog.density);
	terrainShader->SetUniform1f("fog.gradient", fog.gradient);
	terrainShader->Unbind();

	waterShader->Bind();
	waterShader->SetUniformDirectionalLight("directionalLight", *directionalLight);
	waterShader->SetUniform1f("specularLight.materialIntensity", waterMaterial->specularIntensity);
	waterShader->SetUniform1f("specularLight.power", waterMaterial->specularPower);
	waterShader->SetUniform3f("skyColor", skyColor.ToVector3());
	waterShader->SetUniform1f("fog.density", fog.density);
	waterShader->SetUniform1f("fog.gradient", fog.gradient);
	waterShader->Unbind();
}
Scene::~Scene() {
}

void Scene::Draw() {
	waterFrameBuffer->BindReflectionBuffer();
	waterFrameBuffer->Clear();
	terrainRenderer->Draw(terrains);
	waterFrameBuffer->UnbindBuffer();

	terrainRenderer->Draw(terrains);
	waterRenderer->Draw(waters);
	uiRenderer->Draw(uiTextures);
}