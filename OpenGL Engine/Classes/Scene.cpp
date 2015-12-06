#include "Scene.h"
#include "Homework\Polygon2D.h"
#include "Homework\Triangle.h"
#include "TestObject.h"
#include "Homework\Circle.h"

Scene::Scene() {
	//Triangle* triangle = new Triangle("triangle.txt");
	//Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
	//TestObject* testObject = new TestObject();
	Circle* circle = new Circle(Vector3(0.0, 0.5, 0.0), 0.3);
	//Triangle* triangle = new Triangle("triangle.txt");
	//Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
	//TestObject* testObject = new TestObject();
}

Scene::~Scene() {
}