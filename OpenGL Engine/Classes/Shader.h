#ifndef __SHADER_H__
#define __SHADER_H__

#include "Utils/Math/Matrix4.h"
#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader {
private:
	GLuint vertexShader, fragmentShader, shaderProgram;
	void CompileShaders(const char* vertexSource, const char* fragmentSource);
	GLuint Compile(GLuint type, const char* source);

public:
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	void Bind();
	void Unbind();
	void SetUniformMatrix4fv(const char* name, Matrix4 matrix);
};

#endif //__SHADER_H__