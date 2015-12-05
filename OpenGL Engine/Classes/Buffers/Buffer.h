#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <GL/glew.h>

class Buffer {
private:
	GLuint bufferID;
	GLsizei componentCount;
public:
	Buffer(GLfloat* data, GLsizei count, GLsizei componentCount);
	~Buffer();
	void Bind();
	void Unbind();

	GLsizei GetComponentCount();
};

#endif // __BUFFER_H__