#include "math_h.h"
#include <algorithm>
#include <glm\glm.hpp>
#include <glm\gtx\intersect.hpp>

float ToRadians(float angle) {
	return angle * 3.14159265359f / 180.0f;
}

float Clamp(float value, float left, float right) {
	value = std::max(value, left);
	value = std::min(value, right);
	return value;
}

// https://www.opengl.org/discussion_boards/showthread.php/138914-Terrain-Renderer-How-to-Get-Height-at-x-y
// https://books.google.ro/books?id=kwQuwDmfthwC&pg=PA228&lpg=PA228&dq=walking+on+terrain+3d+game&source=bl&ots=LbdhoAWfzy&sig=70IK8q3EDvCwUGmYZDVwIOLBYj4&hl=en&ei=ikrpTdaADOLZ0QHqv52RAQ&sa=X&oi=book_result&ct=result#v=onepage&q=walking%20on%20terrain%203d%20game&f=false
// http://gamedev.stackexchange.com/questions/15907/walkin-on-terrain-opengl
// http://www.3dgep.com/multi-textured-terrain-in-opengl/

float GetYCoord(const Vector3& p1, const Vector3& p2, const Vector3& p3, const float& x, const float& z) {
	Vector3 p1p2 = p2 - p1, p1p3 = p3 - p1;
	Vector3 p1p2Xp1p3 = Vector3::CrossProduct(p1p2, p1p3);
	float a = p1p2Xp1p3.x, b = p1p2Xp1p3.y, c = p1p2Xp1p3.z;
	float d = -(a * p1.x + b * p1.y + c * p1.z);

	return -(a * x + c * z + d) / b;
}