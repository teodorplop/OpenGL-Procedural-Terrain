#include "TestObject.h"

TestObject::TestObject() {
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, 0.5f, 0.0f, 1.0f
	};
	GLfloat colors[] = {
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f
	};
	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	vertexArray = new VertexArray();
	Buffer* positionBuffer = new Buffer(vertices, 4 * 4, 4);
	Buffer* colorBuffer = new Buffer(colors, 4 * 4, 4);
	indexBuffer = new IndexBuffer(indices, 6);

	vertexArray->AddBuffer(positionBuffer, 0);
	vertexArray->AddBuffer(colorBuffer, 1);

	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
}

TestObject::~TestObject() {
}

void TestObject::Draw() {
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	shader->SetUniformMatrix4fv("gWorld", worldMatrix);
	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}

void TestObject::Update() {
	//Vector3 rotation = GetRotation();
	//SetRotation(rotation.z + 1.0f, Vector3(0.0f, 0.0f, 1.0f));
}