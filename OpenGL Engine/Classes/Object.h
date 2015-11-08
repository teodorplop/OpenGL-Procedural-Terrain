#include "Shader.h"
class Object {
	friend class ObjectManager;

protected:
	Shader* shader;

private:
	void Update();
protected:
	virtual void Draw();
public:
	Object();
	~Object();
	void SetShader(const char* vertexPath, const char* fragmentPath);
};