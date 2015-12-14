#include "Scene.h"
#include "Homework\Polygon2D.h"
#include "Homework\Triangle.h"
#include "TestObject.h"
#include "Homework\Circle.h"
#include "Homework\Star.h"
#include "Homework\Comet.h"

#include <iostream>

Scene::Scene() {
	//Triangle* triangle = new Triangle("triangle.txt");
	//Polygon2D* polygon = Polygon2D::ReadFromFile("polygon.txt");
	//TestObject* testObject = new TestObject();
	circle = new Circle(Vector3(-0.2f, -0.2f, 0.0f), 0.2f, Color::yellow);
	circle2 = new Circle(Vector3(0.1f, 0.1f, 0.0f), 0.1f, Color::blue);
	circle3 = new Circle(Vector3(0.215f, 0.215f, 0.0f), 0.05f, Color::red);

	//circle->GetTransform()->TranslateTo(Vector3(-0.2f, -0.2f, 0.0f));
	//circle2->GetTransform()->TranslateTo(Vector3(0.1f, 0.1f, 0.0f));
	//circle3->GetTransform()->TranslateTo(Vector3(0.215f, 0.215f, 0.0f));

	Comet* comet = new Comet();
	comet->GetTransform()->TranslateTo(Vector3(0.9f, 0.9f));
	comet->GetTransform()->RotateBy(-30.0f, Vector3(0.0f, 0.0f, 1.0f));
}

Scene::~Scene() {
}

float angle = 0.0f, angle2 = 0.0f, angle3 = 0.0f;
float step = 1.0f, step2 = 1.0f;
int frameCount = 0, delay = 1000;
void Scene::Update() {
	angle += step;
	angle2 += step * 4;

	if (angle >= 360.0f) {
		angle -= 360.0f;
	}
	if (angle2 >= 360.0f) {
		angle2 -= 360.0f;
	}

	//circle->GetTransform()->TranslateBy(Vector3(0.001f, 0.0f, 0.0f));
	//circle2->GetTransform()->matrix.Multiply(circle->GetTransform()->matrix);
	//circle2->GetTransform()->RotateAroundBy(circle->GetTransform()->position, Vector3(0.0f, 0.0f, 1.0f), 1.5f);
	//circle3->GetTransform()->RotateAroundBy(circle2->GetTransform()->position, Vector3(0.0f, 0.0f, 1.0f), 10.0f);

	//std::cout << circle->GetTransform()->position;
	//std::cout << circle2->GetTransform()->position;
	//std::cout << circle2->GetTransform()->rotation;

	Matrix4 circleMatrix = Matrix4::Translation(Vector3(angle2 / 750.0f, 0.0f, 0.0f));
	circle->GetTransform()->matrix = circleMatrix;

	Matrix4 circle2Matrix = circleMatrix;
	circle2Matrix *= Matrix4::Translation(Vector3(-0.2f, -0.2f, 0.0f));
	circle2Matrix *= Matrix4::Rotation(angle, Vector3(0.0f, 0.0f, 1.0f));
	circle2Matrix *= Matrix4::Translation(Vector3(0.2f, 0.2f, 0.0f));
	circle2->GetTransform()->matrix = circle2Matrix;

	Matrix4 circle3Matrix = circle2Matrix;
	circle3Matrix *= Matrix4::Translation(Vector3(0.1f, 0.1f, 0.0f));
	circle3Matrix *= Matrix4::Rotation(angle2, Vector3(0.0f, 0.0f, 1.0f));
	circle3Matrix *= Matrix4::Translation(Vector3(-0.1f, -0.1f, 0.0f));
	circle3->GetTransform()->matrix = circle3Matrix;

	frameCount++;
	if (frameCount == 50) {
		frameCount = 0;
		Star* star = new Star();
		star->SetTimer(525);
		Vector3 position = Vector3((float)(rand() % 20 - 10) / 10.0f, (float)(rand() % 20 - 10) / 10.0f);
		Vector3 scale = Vector3((float)(rand() % 5) / 10.0f + 0.25f, (float)(rand() % 5) / 10.0f + 0.25f);
		star->GetTransform()->TranslateTo(position);
		star->GetTransform()->ScaleTo(scale);
	}
}