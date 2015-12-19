#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Shader.h"
#include "Transform.h"
#include "Buffers\Buffer.h"
#include "Buffers\VertexArray.h"
#include "Buffers\IndexBuffer.h"
#include "Utils\Math\Vector3.h"

class Object {
	friend class ObjectManager;

protected:
	VertexArray* vertexArray;
	IndexBuffer* indexBuffer;
	Shader* shader;
	Transform* transform;

private:
	int ID;
	void Draw();
	virtual void Update();
	
public:
	Object();
	~Object();
	void SetShader(Shader* shader);
	Shader* GetShader();
	Transform* GetTransform();
};

#endif //__OBJECT_H__