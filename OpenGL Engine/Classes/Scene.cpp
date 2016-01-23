#include "Scene.h"
#include <GL\freeglut.h>

#include "Core/Window.h"
#include "Core/Renderer.h"

Scene::Scene() {
	Window* window = Window::GetWindow();
	int width = window->GetWidth(), height = window->GetHeight();

	camera = new Camera(Projection::Perspective, 15.0f, (float)width / height);
	cameraController = new CameraController();

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
	texture = new Texture("Textures/test.jpg");
	model = new RawModel(vertexArray, indexBuffer);
	texturedModel = new TexturedModel(model, texture);

	objModel = RawModel::LoadFromObj("Obj/suzanne.obj");
	texturedObjModel = new TexturedModel(objModel, texture);
	objModel->GetTransform()->TranslateTo(Vector3(0.0f, 0.0f, 50.0f));
}

Scene::~Scene() {
}

void Scene::Draw() {
	shader->Bind();

	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->SetUniformMatrix4fv("gCamera", cameraController->GetTransform()->GetMatrix());

	shader->SetUniformMatrix4fv("gWorld", texturedModel->GetModel()->GetTransform()->GetMatrix());
	Renderer::Draw(texturedModel);

	//shader->SetUniformMatrix4fv("gWorld", objModel->GetTransform()->GetMatrix());
	//Renderer::Draw(texturedObjModel);

	shader->Unbind();
}