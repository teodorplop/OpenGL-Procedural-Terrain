#include "Polygon2D.h"
#include <cstdio>

Polygon2D::Polygon2D() {
}

Polygon2D::~Polygon2D() {
}

Polygon2D* Polygon2D::ReadFromFile(const char* fileName) {
	FILE* file = fopen(fileName, "r");
	if (file == nullptr) {
		fprintf(stderr, "Could not find file %s\n", fileName);
		return nullptr;
	}

	int n;
	fscanf(file, "%d\n", &n);
	std::vector<Vector2> points(n);
	for (int i = 0; i < n; ++i) {
		fscanf(file, "%f %f\n", &points[i].x, &points[i].y);
	}
	std::vector<Segment2D> segments(n);
	for (int i = 0; i < n; ++i) {
		segments[i].a = points[i];
		segments[i].b = points[(i + 1) % n];
	}

	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 2; j < n; ++j) {
			if (i == 0 && j == n - 1) {
				continue;
			}
			
			bool intersects = Segment2D::Intersects(segments[i], segments[j]);
			segments[i].intersects |= intersects;
			segments[j].intersects |= intersects;
		}
	}

	Polygon2D* polygon = new Polygon2D();
	Shader* shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	Shader* shader2 = new Shader("Shaders/Shader2.vert", "Shaders/Shader2.frag");
	for (int i = 0; i < n; ++i) {
		Segment* segment = new Segment(segments[i].a, segments[i].b, segments[i].intersects ? shader2 : shader);
		polygon->segments.push_back(segment);
	}

	return polygon;
}