#pragma once

#include "Utils/Math/Matrix4.h"
#include "Utils/Math/Vector3.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Effects\DirectionalLight.h"

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
	void SetUniformMatrix4fv(const char* name, const Matrix4& matrix);
	void SetUniform1f(const char* name, const float& value);
	void SetUniform3f(const char* name, const Vector3& vector);
	void SetUniform4f(const char* name, const Vector4& vector);
	void SetUniform1i(const char* name, const int& value);

	void SetUniformDirectionalLight(const char* name, const DirectionalLight& light);
};