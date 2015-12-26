#include "Scene.h"
#include "TestObject.h"
#include "Camera.h"
#include <GL\freeglut.h>

Scene::Scene() {
	int width = glutGet(GLUT_WINDOW_WIDTH), height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = (float)width / height;

	Camera* camera = new Camera(Projection::Perspective, 15.0f, aspectRatio);

	TestObject* obj1 = new TestObject(Color::red);
}

Scene::~Scene() {
}