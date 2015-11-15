#include "Engine.h"

#include "TimeFrame.h"
#include "ObjectManager.h"
#include "Scene.h"

Engine* Engine::instance = nullptr;

void Engine::Start(int argc, char** argv) {
	if (instance == nullptr) {
		instance = new Engine(argc, argv);
		glutMainLoop();
	}
}

Engine::Engine(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Tutorial");

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fprintf(stderr, "Failed to initialize glew: %s\n", glewGetErrorString(error));
	}

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glutDisplayFunc(RenderFunction);
	glutCloseFunc(CleanUpFunction);

	ObjectManager::Start();
	TimeFrame::Start();

	Scene* scene = new Scene();
}

void Engine::Update() {
	ObjectManager::Update();

	glutPostRedisplay();
}

void Engine::RenderFunction() {
	instance->Render();
}

void Engine::CleanUpFunction() {
	instance->CleanUp();
}

void Engine::Render() {
	glClear(GL_COLOR_BUFFER_BIT);

	ObjectManager::Draw();

	glutSwapBuffers();
	glFlush();
}

void Engine::CleanUp() {
	ObjectManager::CleanUp();
}

/*void Engine::createVBO() {
	GLfloat vertices[] = {
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f
	};

	// se creeaza un buffer nou
	glGenBuffers(1, &vboId);
	// este setat ca buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	// punctele sunt "copiate" in bufferul curent
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// se activeaza lucrul cu atribute; atributul 0 = pozitie
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
}
void Engine::destroyVBO() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &ColorBufferId);
	glDeleteBuffers(1, &vboId);
}

void Engine::createShaders() {
	Shader* myShader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	myShader->Bind();

	scale += 0.01f;
	Matrix4 matrix = Matrix4::Rotation(scale, 'Z');

	GLint gWorld = glGetUniformLocation(myShader->GetProgram(), "gWorld");

	glUniformMatrix4fv(gWorld, 1, GL_TRUE, &matrix.elements[0][0]);

	delete myShader;
}
void Engine::destroyShaders() {
}*/