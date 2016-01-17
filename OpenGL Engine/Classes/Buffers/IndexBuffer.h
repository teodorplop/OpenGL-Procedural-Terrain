#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

#include<GL/glew.h>
#include <vector>

class IndexBuffer {
private:
	GLuint bufferID;
	GLsizei count;
public:
	IndexBuffer(GLuint* data, GLsizei count);
	IndexBuffer(const std::vector<unsigned int>& data);
	~IndexBuffer();
	void Bind();
	void Unbind();
	GLsizei GetCount();
};

#endif //__INDEX_BUFFER_H__