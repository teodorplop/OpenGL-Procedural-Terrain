#pragma once

#include "Object.h"
#include "Shader.h"

#include "Buffers\VertexArray.h"
#include "Buffers\IndexBuffer.h"

class RawModel : public Object {
	friend class Renderer;

private:
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;
	Shader* shader;

protected:
	virtual void Draw();

public:
	RawModel();
	~RawModel();
};

