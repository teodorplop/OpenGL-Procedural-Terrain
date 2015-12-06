#include "Scene.h"
#include "Homework\Polygon2D.h"
#include "Homework\Triangle.h"
#include "TestObject.h"
#include "Homework\Circle.h"

Scene::Scene() {
	//Triangle* triangle = new Triangle("triangle.txt");
	//Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
	circle = new Circle(Vector3(-0.1f, -0.1f, 0.0f), 0.2f, Color(49.0f / 255.0f, 181.0f / 255.0f, 80.0f / 255.0f, 1.0f));
	circle2 = new Circle(Vector3(0.35f, 0.35f, 0.0f), 0.1f, Color::blue);
	circle3 = new Circle(Vector3(0.215f, 0.215f, 0.0f), 0.05f, Color::red);
}

Scene::~Scene() {
}

float angle = 0.0f;
float angle2 = 0.0f;
void Scene::Update() {
	angle += 1.0f;
	if (angle >= 360.0f) {
		angle -= 360.0f;
	}
	angle2 += 4.0f;
	if (angle2 >= 360.0f) {
		angle2 -= 360.0f;
	}

	Matrix4 circle2Matrix = Matrix4::Translation(Vector3(-0.1f, -0.1f, 0.0f));
	circle2Matrix *= Matrix4::Rotation(angle, Vector3(0.0f, 0.0f, 1.0f));
	circle2Matrix *= Matrix4::Translation(Vector3(0.1f, 0.1f, 0.0f));
	circle2->worldMatrix = circle2Matrix;

	Matrix4 circle3Matrix = circle2Matrix;
	circle3Matrix *= Matrix4::Translation(Vector3(0.35f, 0.35f, 0.0f));
	circle3Matrix *= Matrix4::Rotation(angle2, Vector3(0.0f, 0.0f, 1.0f));
	circle3Matrix *= Matrix4::Translation(Vector3(-0.35f, -0.35f, 0.0f));
	circle3->worldMatrix = circle3Matrix;
}