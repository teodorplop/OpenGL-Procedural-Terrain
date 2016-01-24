#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"

Scene::Scene() {
	Window* window = Window::GetWindow();
	int width = window->GetWidth(), height = window->GetHeight();

	camera = new Camera(Projection::Perspective, 45.0f, (float)width / height, 1.0f, 500.0f);
	cameraController = new CameraController(camera->GetTransform());
	camera->GetTransform()->TranslateTo(Vector3(0.0f, 10.0f, -10.0f));

	skyColor = Color::grey;
	glClearColor(skyColor.r, skyColor.g, skyColor.b, skyColor.a);
	fog = Fog();

	directionalLight = new DirectionalLight(Color::white, 0.5f, Vector3(-1.0f, -1.0f), 0.75f);
	material = new Material(0.5f, 32.0f);

	treeTexture = new Texture("Textures/Terrain/lowPolyTree.png");
	treeModel = RawModel::LoadFromObj("Obj/Terrain/lowPolyTree.obj");
	treeTexturedModel = new TexturedModel(treeModel, treeTexture);

	for (int i = 0; i < 100; ++i) {
		GameObject* tree = new GameObject(treeTexturedModel);
		tree->GetTransform()->TranslateTo(Vector3(Random::Range(-800.0f, 800.0f), 0.0f, Random::Range(-800.0f, 800.0f)));
		objects.push_back(tree);
	}

	tree2Texture = new Texture("Textures/Terrain/tree.png");
	tree2Model = RawModel::LoadFromObj("Obj/Terrain/tree.obj");
	tree2TexturedModel = new TexturedModel(tree2Model, tree2Texture);

	for (int i = 0; i < 100; ++i) {
		GameObject* tree = new GameObject(tree2TexturedModel);
		tree->GetTransform()->TranslateTo(Vector3(Random::Range(-800.0f, 800.0f), 0.0f, Random::Range(-800.0f, 800.0f)));
		tree->GetTransform()->ScaleTo(Vector3(6.0f, 6.0f, 6.0f));
		objects.push_back(tree);
	}

	grassTexture = new Texture("Textures/Terrain/grassTexture.png", true);
	grassModel = RawModel::LoadFromObj("Obj/Terrain/grassModel.obj");
	grassTexturedModel = new TexturedModel(grassModel, grassTexture);

	for (int i = 0; i < 1000; ++i) {
		GameObject* grass = new GameObject(grassTexturedModel);
		grass->GetTransform()->TranslateTo(Vector3(Random::Range(-800.0f, 800.0f), 0.0f, Random::Range(-800.0f, 800.0f)));
		objects.push_back(grass);
	}

	fernTexture = new Texture("Textures/Terrain/fern.png", true);
	fernModel = RawModel::LoadFromObj("Obj/Terrain/fern.obj");
	fernTexturedModel = new TexturedModel(fernModel, fernTexture);

	for (int i = 0; i < 1000; ++i) {
		GameObject* fern = new GameObject(fernTexturedModel);
		fern->GetTransform()->TranslateTo(Vector3(Random::Range(-800.0f, 800.0f), 0.0f, Random::Range(-800.0f, 800.0f)));
		objects.push_back(fern);
	}

	Texture* backgroundTexture = new Texture("Textures/Terrain/grass.png");
	Texture* rTexture = new Texture("Textures/Terrain/mud.png");
	Texture* gTexture = new Texture("Textures/Terrain/grassFlowers.png");
	Texture* bTexture = new Texture("Textures/Terrain/path.png");
	TerrainTexturePack* terrainTexturePack = new TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);

	Texture* blendMapTexture = new Texture("Textures/Terrain/blendMap.png");

	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			Terrain* terrain = new Terrain(i, j, terrainTexturePack, blendMapTexture, "Textures/Terrain/heightMap.png");
			terrains.push_back(terrain);
		}
	}

	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	renderer = new Renderer(shader, camera);
	terrainShader = new Shader("Shaders/TerrainShader.vert", "Shaders/TerrainShader.frag");
	terrainRenderer = new TerrainRenderer(terrainShader, camera);
}

Scene::~Scene() {
}

void Scene::Draw() {
	terrainShader->Bind();
	terrainShader->SetUniformDirectionalLight("directionalLight", *directionalLight);
	terrainShader->SetUniform1f("specularLight.materialIntensity", material->specularIntensity);
	terrainShader->SetUniform1f("specularLight.power", material->specularPower);
	terrainShader->SetUniform3f("skyColor", skyColor.ToVector3());
	terrainShader->SetUniform1f("fog.density", fog.density);
	terrainShader->SetUniform1f("fog.gradient", fog.gradient);
	terrainShader->Unbind();

	terrainRenderer->Draw(terrains);

	shader->Bind();
	shader->SetUniformDirectionalLight("directionalLight", *directionalLight);
	shader->SetUniform1f("specularLight.materialIntensity", material->specularIntensity);
	shader->SetUniform1f("specularLight.power", material->specularPower);
	shader->SetUniform3f("skyColor", skyColor.ToVector3());
	shader->SetUniform1f("fog.density", fog.density);
	shader->SetUniform1f("fog.gradient", fog.gradient);
	shader->Unbind();

	renderer->Draw(objects);
}