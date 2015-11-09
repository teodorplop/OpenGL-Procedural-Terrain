#include "Segment.h"
#include <cstdio>
#include <iostream>

Segment::Segment() {}
Segment::Segment(Vector2 point1, Vector2 point2) {
	this->point1 = point1, this->point2 = point2;

	GLfloat Vertices[] = {
		this->point1.x, this->point1.y, 0.0f, 1.0f,
		this->point2.x, this->point2.y, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f
	};

	// se creeaza un buffer nou
	glGenBuffers(1, &vboID);
	// este setat ca buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	// punctele sunt "copiate" in bufferul curent
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	// este scos din buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Segment::~Segment() {
	glDeleteBuffers(1, &vboID);
}

void Segment::Draw() {
	shader->Bind();

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	shader->Unbind();
}
