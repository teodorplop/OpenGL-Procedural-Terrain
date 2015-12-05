#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

#include <GL/glew.h>
#include <vector>
#include "Buffer.h"

class VertexArray {
private:
	GLuint arrayID;
	std::vector<Buffer*> buffers;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(Buffer* buffer, GLuint index);
	void Bind();
	void Unbind();
};

#endif //__VERTEX_ARRAY_H__