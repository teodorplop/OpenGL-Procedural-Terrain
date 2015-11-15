#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Shader.h"
class Object {
	friend class ObjectManager;

protected:
	GLuint vboID;
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