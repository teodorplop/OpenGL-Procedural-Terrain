#include "Scene.h"
#include "GameObject.h"
#include <GL\freeglut.h>

#include "Camera.h"
#include "Homework\TestComponent.h"
#include "Homework\CameraController.h"

Scene::Scene() {
	int width = glutGet(GLUT_WINDOW_WIDTH), height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = (float)width / height;

	GameObject* cameraObject = new GameObject();
	cameraObject->AddComponent(new Camera(Projection::Perspective, 45.0f, aspectRatio));
	cameraObject->AddComponent(new CameraController());

	GameObject* obj = new GameObject();
	TestComponent* comp = new TestComponent();
	obj->AddComponent(comp);
}

Scene::~Scene() {
}