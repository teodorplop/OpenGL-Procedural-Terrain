#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <GL/glew.h>

class Buffer {
private:
	GLuint bufferID;
	GLuint componentCount;
public:
	Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
	~Buffer();
	void Bind();
	void Unbind();
};

#endif // __BUFFER_H__