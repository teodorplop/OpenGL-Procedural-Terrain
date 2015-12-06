#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Shader.h"
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

protected:
	virtual void Update();
	virtual void Draw();
public:
	Object();
	~Object();
	void SetShader(Shader* shader);

private:
	Matrix4 translationMatrix;
	Matrix4 rotationMatrix;
	Matrix4 scaleMatrix;
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void UpdateWorldMatrix();

protected:
	Matrix4 worldMatrix;

public:
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	void SetRotation(float angle, Vector3 axis);
	Vector3 GetRotation();
	void SetScale(Vector3 scale);
	Vector3 GetScale();
};

#endif //__OBJECT_H__