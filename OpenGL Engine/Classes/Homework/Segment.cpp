#include "Segment.h"
#include <cstdio>

Segment::Segment() {}
Segment::Segment(Vector2 point1, Vector2 point2, Shader* shader, Matrix4 worldMatrix) {
	this->point1 = point1, this->point2 = point2;
	this->worldMatrix = worldMatrix;
	timePassed = 0.0f;

	GLfloat vertices[] = {
		this->point1.x, this->point1.y, 0.0f, 1.0f,
		this->point2.x, this->point2.y, 0.0f, 1.0f
	};
	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f
	};
	GLuint indices[] = {
		0, 1
	};

	vertexArray = new VertexArray();
	Buffer* positionBuffer = new Buffer(vertices, 2 * 4, 4);
	Buffer* colorBuffer = new Buffer(colors, 2 * 4, 4);
	indexBuffer = new IndexBuffer(indices, 2);

	vertexArray->AddBuffer(positionBuffer, 0);
	vertexArray->AddBuffer(colorBuffer, 1);

	SetShader(shader);
}

Segment::~Segment() {
}

void Segment::Draw() {
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	shader->SetUniformMatrix4fv("gWorld", worldMatrix);
	glDrawElements(GL_LINES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}

void Segment::Update() {

}