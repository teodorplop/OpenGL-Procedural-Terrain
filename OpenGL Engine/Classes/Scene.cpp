#include "Scene.h"
#include "Homework\Polygon2D.h"
#include "Homework\Triangle.h"

Scene::Scene() {
	Triangle* triangle = new Triangle("triangle.txt");
}

Scene::~Scene() {
}