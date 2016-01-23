#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Utils\Random.h"

Scene::Scene() {
	Window* window = Window::GetWindow();
	int width = window->GetWidth(), height = window->GetHeight();

	camera = new Camera(Projection::Perspective, 15.0f, (float)width / height);
	cameraController = new CameraController(camera);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 2.0f, 1.0f,
		0.5f, 0.5f, 2.0f, 1.0f,
		0.5f, -0.5f, 2.0f, 1.0f,
		-0.5f, 0.5f, 2.0f, 1.0f
	};
	GLfloat uvs[] = {
		0.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 1.0f
	};
	GLuint indices[] = {
		0, 2, 1,
		0, 1, 3
	};

	VertexArray* vertexArray = new VertexArray();
	Buffer* verticesBuffer = new Buffer(vertices, 16, 4);
	Buffer* textureBuffer = new Buffer(uvs, 8, 2);
	IndexBuffer* indexBuffer = new IndexBuffer(indices, 6);
	vertexArray->AddBuffer(verticesBuffer, 0);
	vertexArray->AddBuffer(textureBuffer, 1);

	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	texture = new Texture("Textures/stall.jpg");

	model = new RawModel(vertexArray, indexBuffer);
	texturedModel = new TexturedModel(model, texture);

	objModel = RawModel::LoadFromObj("Obj/stall.obj");
	texturedObjModel = new TexturedModel(objModel, texture);

	directionalLight = new DirectionalLight(Color::white, 0.75f, Vector3(-1.0f, -1.0f), 0.75f);
	material = new Material(10.0f, 1.0f);

	GameObject* go = new GameObject(texturedObjModel);
	objects.push_back(go);
}

Scene::~Scene() {
}

void Scene::Draw() {
	shader->Bind();

	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->SetUniformMatrix4fv("gCamera", camera->GetTransform()->GetMatrix());
	shader->SetUniformDirectionalLight("directionalLight", *directionalLight);
	shader->SetUniform1f("specularLight.shineDamper", material->shineDamper);
	shader->SetUniform1f("specularLight.reflectivity", material->reflectivity);

	for (unsigned int i = 0; i < objects.size(); ++i) {
		shader->SetUniformMatrix4fv("gWorld", objects[i]->GetTransform()->GetMatrix());
		Renderer::Draw(texturedObjModel);
	}

	shader->Unbind();
}