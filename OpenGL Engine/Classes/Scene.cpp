#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"
#include "Terrain/HeightMapGenerator.h"
#include "Core\Input.h"

#include "Utils/FileUtils.h"
#include "Utils/StringUtils.h"

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
	terrainTexture = new Texture("Textures/Terrain/grass.png");

	this->terrainSeed = 0;
	this->terrainOctaves = 7;
	this->heightMapResolution = 256;
	this->dirty = false;
	RefreshTerrain();

	terrainMaterial = new Material(0.25f, 32.0f);
	terrainShader = new Shader("Shaders/TerrainShader.vert", "Shaders/TerrainShader.frag");
	terrainRenderer = new TerrainRenderer(terrainShader, camera);

	// WATER
	Water* water = new Water(0, 0);
	waters.push_back(water);

	waterMaterial = new Material(0.25f, 32.0f);
	waterShader = new Shader("Shaders/WaterShader.vert", "Shaders/WaterShader.frag");
	waterFrameBuffer = new WaterFrameBuffer();
	waterRenderer = new WaterRenderer(waterShader, camera, waterFrameBuffer);

	// UI
	/*UITexture* reflectionTexture = new UITexture(waterFrameBuffer->GetReflectionTexture());
	reflectionTexture->GetGameObject()->GetTransform()->ScaleTo(Vector3(0.5f, 0.5f, 1.0f));
	reflectionTexture->GetGameObject()->GetTransform()->TranslateTo(Vector3(-1.0f, 1.0f));
	UITexture* refractionTexture = new UITexture(waterFrameBuffer->GetRefractionTexture());
	refractionTexture->GetGameObject()->GetTransform()->ScaleTo(Vector3(0.5f, 0.5f, 1.0f));
	refractionTexture->GetGameObject()->GetTransform()->TranslateTo(Vector3(1.0f, 1.0f));
	uiTextures.push_back(reflectionTexture);
	uiTextures.push_back(refractionTexture);*/

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
	delete camera;
	delete cameraController;
}

void Scene::Draw() {
	Vector3 cameraPosition = camera->GetTransform()->GetPosition();
	cameraPosition.y = -cameraPosition.y;
	camera->GetTransform()->TranslateTo(cameraPosition);

	glEnable(GL_CLIP_DISTANCE0);
	waterFrameBuffer->BindReflectionBuffer();
	waterFrameBuffer->Clear();
	terrainRenderer->Draw(terrains, Vector4(0, 1, 0, 0));
	waterFrameBuffer->UnbindBuffer();
	cameraPosition.y = -cameraPosition.y;
	camera->GetTransform()->TranslateTo(cameraPosition);

	waterFrameBuffer->BindRefractionBuffer();
	waterFrameBuffer->Clear();
	terrainRenderer->Draw(terrains, Vector4(0, -1, 0, 0));
	waterFrameBuffer->UnbindBuffer();

	glDisable(GL_CLIP_DISTANCE0);
	terrainRenderer->Draw(terrains, Vector4(0, -1, 0, 10000));
	waterRenderer->Draw(waters);
	//uiRenderer->Draw(uiTextures);
}

void Scene::Update() {
	if (dirty) {
		dirty = false;
		RefreshTerrain();
	}
}

void Scene::RefreshTerrain() {
	for (unsigned int i = 0; i < terrains.size(); ++i) {
		delete terrains[i];
	}
	terrains.clear();
	for (unsigned int i = 0; i < waters.size(); ++i) {
		delete waters[i];
	}
	waters.clear();

	HeightMapGenerator::Generate("heightMap", heightMapResolution, heightMapResolution, terrainOctaves, terrainSeed);
	Terrain* terrain = new Terrain(0, 0, terrainTexture, "Textures/Terrain/HeightMaps/heightMap.png");
	terrains.push_back(terrain);

	Water* water = new Water(0, 0);
	waters.push_back(water);
}

void Scene::SetSeed(int seed) {
	if (this->terrainSeed != seed) {
		this->terrainSeed = seed;
		this->dirty = true;
	}
}
void Scene::SetHeightMapRes(int res) {
	if (this->heightMapResolution != res) {
		this->heightMapResolution = res;
		this->dirty = true;
	}
}
void Scene::SetOctaves(int octaves) {
	if (this->terrainOctaves != octaves) {
		this->terrainOctaves = octaves;
		this->dirty = true;
	}
}
void Scene::SetTerrainSize(float size) {
	if (Terrain::size != size) {
		Terrain::size = size;
		this->dirty = true;
	}
}
void Scene::SetTerrainHeight(float height) {
	if (Terrain::maxHeight != height) {
		Terrain::maxHeight = height;
		this->dirty = true;
	}
}