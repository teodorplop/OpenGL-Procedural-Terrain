#include "Segment2D.h"

Segment2D::Segment2D() {
	this->a = Vector2(), this->b = Vector2();
	this->intersects = false;
}
Segment2D::Segment2D(Vector2 a, Vector2 b) {
	this->a = a, this->b = b;
	this->intersects = false;
}

Segment2D::~Segment2D() {
}

bool Segment2D::Intersects(const Segment2D& p0, const Segment2D& p1) {
	float a11 = p0.b.x - p0.a.x;
	float a12 = p1.a.x - p1.b.x;
	float b1 = p1.a.x - p0.a.x;

	float a21 = p0.b.y - p0.a.y;
	float a22 = p1.a.y - p1.b.y;
	float b2 = p1.a.y - p0.a.y;

	float det = (a11 * a22 - a12 * a21);
	if (det == 0) {
		// TODO: cazul segmentelor care se intersecteaza trebuie tratat separat
	}

	float lambda1 = (b1 * a22 - a12 * b2) / det;
	float lambda2 = (b2 * a11 - b1 * a21) / det;

	bool answer = (0 <= lambda1 && lambda1 <= 1 && 0 <= lambda2 && lambda2 <= 1);
	/*if (answer) {
		intersection.x = ((double)1 - lambda1) * p0.a.x + lambda1 * p0.b.x;
		intersection.y = ((double)1 - lambda1) * p0.a.y + lambda1 * p0.b.y;
	}*/

	return answer;
}