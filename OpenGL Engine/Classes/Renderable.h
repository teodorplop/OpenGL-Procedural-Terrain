#pragma once

#include "Component.h"
#include "Shader.h"
#include "Buffers\Buffer.h"
#include "Buffers\VertexArray.h"
#include "Buffers\IndexBuffer.h"
#include "Utils\Math\Vector3.h"

class Renderable : public Component {
	friend class Renderer;

protected:
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;
	Shader* shader;

private:
	void Draw();

public:
	Renderable();
	virtual ~Renderable();
};
