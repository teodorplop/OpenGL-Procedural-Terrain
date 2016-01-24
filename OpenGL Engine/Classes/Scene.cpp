#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"

Scene::Scene() {
	Window* window = Window::GetWindow();
	int width = window->GetWidth(), height = window->GetHeight();

	camera = new Camera(Projection::Perspective, 45.0f, (float)width / height);
	camera->GetTransform()->TranslateTo(Vector3(0.0f, 5.0f));
	cameraController = new CameraController(camera);

	texture = new Texture("Textures/stall.jpg");
	terrainTexture = new Texture("Textures/Terrain/Forest Floor.jpg");

	objModel = RawModel::LoadFromObj("Obj/stall.obj");
	texturedObjModel = new TexturedModel(objModel, texture);

	directionalLight = new DirectionalLight(Color::white, 0.75f, Vector3(-1.0f, -1.0f), 0.75f);
	material = new Material(10.0f, 1.0f);

	GameObject* go = new GameObject(texturedObjModel);
	go->GetTransform()->TranslateTo(Vector3(25.0f, 0.0f, 25.0f));
	objects.push_back(go);

	Terrain* terrain = new Terrain(0, 0, terrainTexture);
	terrains.push_back(terrain);

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