#include "Scene.h"
#include <GL\freeglut.h>

#include "Camera.h"
#include "Homework\CameraController.h"
#include "Homework\TestClass.h"
#include "Lights\Lights.h"

#include "Object.h"

Scene::Scene() {
	int width = glutGet(GLUT_WINDOW_WIDTH), height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = (float)width / height;

	Camera* camera = new Camera(Projection::Perspective, 45.0f, aspectRatio);
}

Scene::~Scene() {
}