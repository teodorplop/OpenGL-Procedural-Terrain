#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Shader.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

class Object {
	friend class ObjectManager;

protected:
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;
	Shader* shader;

protected:
	virtual void Update();
	virtual void Draw();
public:
	Object();
	~Object();
	void SetShader(Shader* shader);
};

#endif//__OBJECT_H__