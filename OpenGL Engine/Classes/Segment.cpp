#include "Segment.h"
#include <cstdio>

Segment::Segment() {}
Segment::Segment(Vector2 point1, Vector2 point2) {
	this->point1 = point1, this->point2 = point2;

	GLfloat Vertices[] = {
		this->point1.x, this->point1.y, 0.0f, 1.0f,
		this->point2.x, this->point2.y, 0.0f, 1.0f
	};

	// se creeaza un buffer nou
	glGenBuffers(1, &vboID);
	// este setat ca buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	// punctele sunt "copiate" in bufferul curent
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// se activeaza lucrul cu atribute; atributul 0 = pozitie
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
}

Segment::~Segment() {
}

void Segment::Draw() {
	shader->use();
	glDrawArrays(GL_LINES, 0, 2);
}
