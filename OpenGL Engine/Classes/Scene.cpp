#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"
#include "Terrain/HeightMapGenerator.h"
#include "Core\Input.h"

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
	backgroundTexture = new Texture("Textures/Terrain/grass.png");
	rTexture = new Texture("Textures/Terrain/mud.png");
	gTexture = new Texture("Textures/Terrain/grassFlowers.png");
	bTexture = new Texture("Textures/Terrain/path.png");
	terrainTexturePack = new TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);
	blendMapTexture = new Texture("Textures/Terrain/blendMap.png");

	key = 8;
	HeightMapGenerator::Generate("heightMap", 256, 256, key);
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

void Scene::RefreshTerrain(int key, bool newSeed) {
	for (unsigned int i = 0; i < terrains.size(); ++i) {
		delete terrains[i];
	}
	terrains.clear();

	this->key = key;
	HeightMapGenerator::Generate("heightMap", 256, 256, key, (int)1000 * Random::Next());
	Terrain* terrain = new Terrain(0, 0, terrainTexturePack, blendMapTexture, "Textures/Terrain/HeightMaps/heightMap.png");
	terrains.push_back(terrain);
}

void Scene::Update() {
	bool newSeed = Input::GetKey((int)'R');
	int newKey = key;

	for (int key = 1; key <= 8; ++key) {
		if (Input::GetKey((int)'0' + key)) {
			newKey = key;
			break;
		}
	}

	if (newSeed || key != newKey) {
		RefreshTerrain(newKey, newSeed);
	}
}