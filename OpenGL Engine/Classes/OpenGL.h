#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class OpenGL {
private:
	static OpenGL* instance;
	static void renderFunction();
	static void cleanUpFunction();

	GLuint VaoId, VboId, ColorBufferId;

	OpenGL(int argc, char** argv);
	void render();
	void cleanUp();

	void createVBO();
	void destroyVBO();

	void createShaders();
	void destroyShaders();

public:
	static void Initialize(int argc, char** argv);
};