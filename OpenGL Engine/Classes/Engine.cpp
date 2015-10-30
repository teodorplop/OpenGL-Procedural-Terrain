#include "Engine.h"

#include <cstdio>

#include "Utils/Math/math_3d.h"
#include "Shader.h"
#include "TimeFrame.h"
#include "ObjectManager.h"

Engine* Engine::instance = nullptr;
float Engine::scale = 0;

void Engine::Initialize(int argc, char** argv) {
	if (instance == nullptr) {
		instance = new Engine(argc, argv);
		glutMainLoop();
	}
}

Engine::Engine(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Tutorial");

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fprintf(stderr, "Failed to initialize glew: %s\n", glewGetErrorString(error));
	}

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glutDisplayFunc(renderFunction);
	glutCloseFunc(cleanUpFunction);

	ObjectManager::Initialize();
	TimeFrame::Start();
}

void Engine::Update() {
	ObjectManager::Update();
}

void Engine::renderFunction() {
	instance->render();
}

void Engine::cleanUpFunction() {
	instance->cleanUp();
}

void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT);
	createVBO();
	createShaders();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glFlush();
}

void Engine::cleanUp() {
	destroyVBO();
	destroyShaders();
}

void Engine::createVBO() {
	GLfloat Vertices[] = {
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f
	};

	// se creeaza un buffer nou
	glGenBuffers(1, &VboId);
	// este setat ca buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
	// punctele sunt "copiate" in bufferul curent
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// se activeaza lucrul cu atribute; atributul 0 = pozitie
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
}
void Engine::destroyVBO() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &ColorBufferId);
	glDeleteBuffers(1, &VboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VaoId);
}

void Engine::createShaders() {
	Shader* myShader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	myShader->use();

	scale += 0.01f;
	Matrix4 matrix = Matrix4::Rotation(scale, 'Z');

	GLint gWorld = glGetUniformLocation(myShader->getProgram(), "gWorld");

	glUniformMatrix4fv(gWorld, 1, GL_TRUE, &matrix.elements[0][0]);

	delete myShader;
}
void Engine::destroyShaders() {
}