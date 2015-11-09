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

	GLuint GetProgram();
	void Bind();
	void Unbind();
};