#include "Scene.h"
#include "Homework\Polygon2D.h"

Scene::Scene() {
	Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
}

Scene::~Scene() {
}