#include "Scene.h"
#include "GameObject.h"
#include <GL\freeglut.h>

#include "Camera.h"
#include "Homework\CameraController.h"
#include "Homework\TestClass.h"

Scene::Scene() {
	int width = glutGet(GLUT_WINDOW_WIDTH), height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = (float)width / height;

	GameObject* cameraObject = new GameObject();
	cameraObject->AddComponent(new Camera(Projection::Perspective, 45.0f, aspectRatio));
	cameraObject->AddComponent(new CameraController());

	GameObject* obj = new GameObject();
	obj->GetTransform()->TranslateTo(Vector3(0.0f, 0.0f, 10.0f));
	obj->GetTransform()->RotateBy(180.0f, Vector3(0.0f, 1.0f, 0.0f));
	TestClass* comp = new TestClass();
	obj->AddComponent(comp);
}

Scene::~Scene() {
}