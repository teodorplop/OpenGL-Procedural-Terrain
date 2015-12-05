#include "Buffer.h"

#include<cstdio>

Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount) {
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Buffer::~Buffer() {
	glDeleteBuffers(1, &bufferID);
}

void Buffer::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void Buffer::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}