#include "Scene.h"
#include "GameObject.h"
#include <GL\freeglut.h>

#include "Camera.h"
#include "Homework\CameraController.h"
#include "Homework\TestClass.h"
#include "Lights\Lights.h"

Scene::Scene() {
	int width = glutGet(GLUT_WINDOW_WIDTH), height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = (float)width / height;

	Lights::AddLight(DirectionalLight(Color::red, 0.5f, Vector3(-1.0f, -1.0f, 0.0f), 0.75f));

	GameObject* cameraObject = new GameObject();
	cameraObject->AddComponent(new Camera(Projection::Perspective, 45.0f, aspectRatio));
	cameraObject->AddComponent(new CameraController());

	GameObject* obj = new GameObject();
	obj->GetTransform()->TranslateTo(Vector3(0.0f, 0.0f, 10.0f));
	obj->GetTransform()->RotateBy(180.0f, Vector3(0.0f, 1.0f, 0.0f));
	TestClass* comp = new TestClass();
	obj->AddComponent(comp);

	GameObject* obj2 = new GameObject();
	obj2->GetTransform()->TranslateTo(Vector3(0.0f, 5.0f, 10.0f));
	obj2->GetTransform()->RotateBy(180.0f, Vector3(0.0f, 1.0f, 0.0f));
	TestClass* comp2 = new TestClass();
	obj2->AddComponent(comp2);
}

Scene::~Scene() {
}