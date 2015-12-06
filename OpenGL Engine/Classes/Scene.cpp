#include "Scene.h"
#include "Homework\Polygon2D.h"
#include "Homework\Triangle.h"
#include "TestObject.h"

Scene::Scene() {
	//Triangle* triangle = new Triangle("triangle.txt");
	//Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
	TestObject* testObject = new TestObject();
	TestObject* testObject2 = new TestObject();
	testObject->SetRotation(90.0f, Vector3(0.0f, 0.0f, 1.0f));
}

Scene::~Scene() {
}