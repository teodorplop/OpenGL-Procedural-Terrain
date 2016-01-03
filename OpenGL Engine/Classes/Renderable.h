#pragma once

#include "Component.h"
#include "Shader.h"
#include "Texture.h"
#include "Buffers\VertexArray.h"
#include "Buffers\IndexBuffer.h"

class Renderable : public Component {
	friend class Renderer;

protected:
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;
	Shader* shader;
	Texture* texture;

private:
	void Draw();

public:
	Renderable();
	virtual ~Renderable();
};
