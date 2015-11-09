#include "Object.h"
#include "Utils/Math/Vector2.h"

class Segment : public Object {
private:
	Vector2 point1, point2;
protected:
  void Draw();
public:
	Segment();
	Segment(Vector2 x, Vector2 y);
	~Segment();
};
