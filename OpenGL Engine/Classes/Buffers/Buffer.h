#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <GL/glew.h>
#include "../Utils/Math/math_3d.h"
#include <vector>

class Buffer {
private:
	GLuint bufferID;
	GLsizei componentCount;
public:
	Buffer(GLfloat* data, GLsizei count, GLsizei componentCount);
	Buffer(const std::vector<Vector2>& data);
	Buffer(const std::vector<Vector3>& data);
	Buffer(const std::vector<Vector4>& data);
	~Buffer();

	void Bind();
	void Unbind();

	GLsizei GetComponentCount();
};

#endif // __BUFFER_H__