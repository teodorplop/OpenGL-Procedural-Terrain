#ifndef __SEGMENT_2D_H__
#define __SEGMENT_2D_H__

#include "../Utils/Math/Vector2.h"

class Segment2D {
public:
	Vector2 a, b;
	bool intersects;

	Segment2D();
	Segment2D(Vector2 a, Vector2 b);
	~Segment2D();

	static bool Intersects(const Segment2D& p0, const Segment2D& p1);
};

#endif // __SEGMENT_2D_H__