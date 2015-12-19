#include "Scene.h"
#include "TestObject.h"

Scene::Scene() {
	TestObject* obj1 = new TestObject(Color::red);
	TestObject* obj2 = new TestObject(Color::blue);
	obj1->GetTransform()->ScaleTo(Vector3(0.5f, 0.5f, 1.0f));
	obj1->GetTransform()->TranslateTo(Vector3(-0.75f, 0.0f, 0.0f));

	obj2->GetTransform()->SetParent(obj1->GetTransform());
	obj2->GetTransform()->TranslateTo(Vector3(0.5f, 0.5f, 0.0f));

	obj2->GetTransform()->RotateAroundBy(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f), 45.0f);
}

Scene::~Scene() {
}