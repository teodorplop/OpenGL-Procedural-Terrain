#include "TestObject.h"

TestObject::TestObject() {
	GLfloat vertices[] = {
		-0.5f, -0.5f, 10.0f, 1.0f,
		0.0f, -0.5f, 15.0f, 1.0f,
		0.5f, -0.5f, 10.0f, 1.0f,
		0.0f, 0.5f, 10.0f, 1.0f
	};
	Color blue = Color::blue;
	Color red = Color::red;
	Color yellow = Color::yellow;
	Color green = Color::green;
	GLfloat colors[] = {
		blue.r, blue.g, blue.b, blue.a,
		red.r, red.g, red.b, red.a,
		yellow.r, yellow.g, yellow.b, yellow.a,
		green.r, green.g, green.b, green.a
		//color.r, color.g, color.b, color.a,
		//color.r, color.g, color.b, color.a,
		//color.r, color.g, color.b, color.a,
		//color.r, color.g, color.b, color.a
	};
	GLuint indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	vertexArray = new VertexArray();
	Buffer* positionBuffer = new Buffer(vertices, 4 * 4, 4);
	Buffer* colorBuffer = new Buffer(colors, 4 * 4, 4);
	indexBuffer = new IndexBuffer(indices, 12);

	vertexArray->AddBuffer(positionBuffer, 0);
	vertexArray->AddBuffer(colorBuffer, 1);

	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
}

TestObject::~TestObject() {
}