#include "Segment.h"
#include <cstdio>
#include <iostream>

Segment::Segment() {}
Segment::Segment(Vector2 point1, Vector2 point2, Shader* shader, Matrix4 worldMatrix) {
	this->point1 = point1, this->point2 = point2;
	this->worldMatrix = worldMatrix;
	timePassed = 0.0f;

	GLfloat vertices[] = {
		this->point1.x, this->point1.y, 0.0f, 1.0f,
		this->point2.x, this->point2.y, 0.0f, 1.0f
	};

	buffer = new Buffer(vertices, 8, 1);
	SetShader(shader);
}

Segment::~Segment() {
}

void Segment::Draw() {
	shader->Bind();
	buffer->Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	GLint gWorld = glGetUniformLocation(shader->GetProgram(), "gWorld");
	glUniformMatrix4fv(gWorld, 1, GL_TRUE, &worldMatrix.elements[0][0]);

	glDrawArrays(GL_LINES, 0, 2);

	glDisableVertexAttribArray(0);

	buffer->Unbind();
	shader->Unbind();
}

void Segment::Update() {

}