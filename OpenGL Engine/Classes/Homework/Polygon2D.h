#include "../Segment.h"
#include "Segment2D.h"
#include <vector>

class Polygon2D {
	std::vector<Segment*> segments;
public:
	Polygon2D();
	~Polygon2D();

	static Polygon2D* ReadFromFile(const char* fileName);
};