#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "../Object.h"
#include "../Utils/Math/Vector2.h"
#include "../Utils/Math/Matrix4.h"

class Segment : public Object {
private:
	Vector2 point1, point2;
	float timePassed;
	Matrix4 worldMatrix;

protected:
  void Draw();
	void Update();
public:
	Segment();
	Segment(Vector2 x, Vector2 y, Shader* shader, Matrix4 worldMatrix = Matrix4(1.0f));
	~Segment();
};

#endif //__SEGMENT_H__