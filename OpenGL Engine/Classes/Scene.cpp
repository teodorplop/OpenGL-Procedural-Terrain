#include "Scene.h"
#include "TestObject.h"
#include "GameObject.h"
#include "Camera.h"
#include "Renderable.h"
#include <GL\freeglut.h>

Scene::Scene() {
	int width = glutGet(GLUT_WINDOW_WIDTH), height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = (float)width / height;

	GameObject* cameraObject = new GameObject();
	cameraObject->AddComponent(new Camera(Projection::Perspective, 15.0f, aspectRatio));

	GameObject* obj = new GameObject();
	TestObject* obj1 = new TestObject();
	obj->AddComponent(obj1);
}

Scene::~Scene() {
}