#include "Triangle.h"
#include<cstdio>
#include<vector>
#include "../Shader.h"
#include "Segment.h"
#include "../Color.h"

Triangle::Triangle(const char* fileName) {
	FILE* file = fopen(fileName, "r");
	if (file == nullptr) {
		fprintf(stderr, "Could not find file %s\n", fileName);
	} else {
		std::vector<Vector2> points(3);
		for (int i = 0; i < 3; ++i) {
			fscanf(file, "%f %f\n", &points[i].x, &points[i].y);
		}

		Shader* shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
		for (int i = 0; i < 3; ++i) {
			Matrix4 world(1.0f);
			Segment* segment = new Segment(points[i], points[(i + 1) % 3], shader, Color::red, world);
		}
		for (int i = 0; i < 3; ++i) {
			Matrix4 world = Matrix4::Rotation(180.0f, Vector3(0.0f, 0.0f, 1.0f));
			Segment* segment = new Segment(points[i], points[(i + 1) % 3], shader, Color::blue, world);
		}
	}
}

Triangle::~Triangle() {
}
