#include "Scene.h"
#include "Homework\Polygon2D.h"
#include "Homework\Triangle.h"
#include "TestObject.h"

Scene::Scene() {
	//Triangle* triangle = new Triangle("triangle.txt");
	Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
	//TestObject* testObject = new TestObject();
}

Scene::~Scene() {
}