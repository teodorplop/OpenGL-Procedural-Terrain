#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "Object.h"
#include "Utils/Math/Vector2.h"

class Segment : public Object {
private:
	Vector2 point1, point2;
protected:
  void Draw();
public:
	Segment();
	Segment(Vector2 x, Vector2 y, Shader* shader);
	~Segment();
};

#endif//__SEGMENT_H__