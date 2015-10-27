#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader {
private:
	GLuint vertexShader, fragmentShader, prog;
	void compileShaders(const char* vertexSource, const char* fragmentSource);
	GLuint compile(GLuint type, const char* source);

public:
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	GLuint getProgram();
	void useShader();
};