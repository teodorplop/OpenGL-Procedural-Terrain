#include "TestObject.h"

TestObject::TestObject(Color color) {
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, 0.5f, 0.0f, 1.0f
	};
	GLfloat colors[] = {
		color.r, color.g, color.b, color.a,
		color.r, color.g, color.b, color.a,
		color.r, color.g, color.b, color.a,
		color.r, color.g, color.b, color.a
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