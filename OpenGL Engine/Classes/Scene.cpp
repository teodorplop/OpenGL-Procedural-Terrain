#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"

Scene::Scene() {
	Window* window = Window::GetWindow();
	int width = window->GetWidth(), height = window->GetHeight();

	camera = new Camera(Projection::Perspective, 45.0f, (float)width / height, 1.0f, 500.0f);
	camera->GetTransform()->TranslateTo(Vector3(0.0f, 5.0f));
	cameraController = new CameraController(camera);

	directionalLight = new DirectionalLight(Color::white, 0.75f, Vector3(-1.0f, -1.0f), 0.75f);
	material = new Material(10.0f, 0.1f);

	treeTexture = new Texture("Textures/Terrain/lowPolyTree.png");
	treeModel = RawModel::LoadFromObj("Obj/Terrain/lowPolyTree.obj");
	treeTexturedModel = new TexturedModel(treeModel, treeTexture);

	for (int i = 0; i < 100; ++i) {
		GameObject* tree = new GameObject(treeTexturedModel);
		tree->GetTransform()->TranslateTo(Vector3(Random::Range(-500.0f, 500.0f), 0.0f, Random::Range(-500.0f, 500.0f)));
		objects.push_back(tree);
	}

	grassTexture = new Texture("Textures/Terrain/grassTexture.png");
	grassModel = RawModel::LoadFromObj("Obj/Terrain/grassModel.obj");
	grassTexturedModel = new TexturedModel(grassModel, grassTexture);

	for (int i = 0; i < 100; ++i) {
		GameObject* grass = new GameObject(grassTexturedModel);
		grass->GetTransform()->TranslateTo(Vector3(Random::Range(-500.0f, 500.0f), 0.0f, Random::Range(-500.0f, 500.0f)));
		objects.push_back(grass);
	}

	terrainTexture = new Texture("Textures/Terrain/grass.png");
	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			Terrain* terrain = new Terrain(i, j, terrainTexture);
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
	terrainShader->SetUniform1f("specularLight.shineDamper", material->shineDamper);
	terrainShader->SetUniform1f("specularLight.reflectivity", material->reflectivity);
	terrainShader->Unbind();

	terrainRenderer->Draw(terrains);

	shader->Bind();
	shader->SetUniformDirectionalLight("directionalLight", *directionalLight);
	shader->SetUniform1f("specularLight.shineDamper", material->shineDamper);
	shader->SetUniform1f("specularLight.reflectivity", material->reflectivity);
	shader->Unbind();

	renderer->Draw(objects);
}