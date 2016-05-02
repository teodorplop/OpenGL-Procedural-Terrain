#pragma once

#include "Object.h"

#include "Buffers\VertexArray.h"
#include "Buffers\IndexBuffer.h"

class RawModel : public Object {
private:
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;

public:
	RawModel(VertexArray* vertexArray, IndexBuffer* indexBuffer);
	~RawModel();
	VertexArray* GetVertexArray();
	IndexBuffer* GetIndexBuffer();

	static RawModel* LoadQuad();
	static RawModel* LoadFromObj(const char* filename);
};

