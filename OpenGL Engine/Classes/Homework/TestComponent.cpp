#include "TestComponent.h"
#include "..\GameObject.h"
#include "..\Color.h"

TestComponent::TestComponent() {
	GLfloat vertices[] = {
		-0.5f, 0.5f, -0.5f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f,

		-0.5f, 0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f,
		-0.5f, -0.5f, 0.5f, 1.0f
	};
	GLfloat colors[] = {
		// front colors
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		// back colors
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};
	GLfloat uvs[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f
	};
	GLuint indices[] = {
		// front
		3, 2, 1,
		3, 1, 0,

		// back
		6, 7, 4,
		6, 4, 5,

		// top
		0, 1, 5,
		0, 5, 4,

		// bottom
		7, 6, 2,
		7, 2, 3,

		// left
		7, 3, 0,
		7, 0, 4,

		// right
		2, 6, 5,
		2, 5, 1
	};

	vertexArray = new VertexArray();
	Buffer* positionBuffer = new Buffer(vertices, 8 * 4, 4);
	Buffer* colorBuffer = new Buffer(colors, 8 * 4, 4);
	Buffer* uvBuffer = new Buffer(uvs, 8 * 2, 2);
	indexBuffer = new IndexBuffer(indices, 36);

	vertexArray->AddBuffer(positionBuffer, 0);
	vertexArray->AddBuffer(colorBuffer, 1);
	vertexArray->AddBuffer(uvBuffer, 2);

	shader = new Shader("Shaders/TextureShader.vert", "Shaders/TextureShader.frag");
	texture = new Texture("test.jpg");
}

TestComponent::~TestComponent() {
}

void TestComponent::Update() {
	gameObject->GetTransform()->RotateBy(1.0f, Vector3(1.0f, 0.0f, 0.0f));
	gameObject->GetTransform()->RotateBy(1.0f, Vector3(0.0f, 1.0f, 0.0f));
	gameObject->GetTransform()->RotateBy(1.0f, Vector3(0.0f, 0.0f, 1.0f));
}