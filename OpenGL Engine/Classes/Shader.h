#ifndef __SHADER_H__
#define __SHADER_H__

#include "Utils/Math/Matrix4.h"
#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Lights\DirectionalLight.h"

class Shader {
private:
	GLuint vertexShader, fragmentShader, shaderProgram;
	void CompileShaders(const char* vertexSource, const char* fragmentSource);
	GLuint Compile(GLuint type, const char* source);

public:
	Shader(const char* vertexFile, const char* fragmentFile);
	virtual ~Shader();

	void Bind();
	void Unbind();
	void SetUniformMatrix4fv(const char* name, Matrix4 matrix);
	void SetUniformDirectionalLight(const char* name, const DirectionalLight& light);
};

#endif //__SHADER_H__