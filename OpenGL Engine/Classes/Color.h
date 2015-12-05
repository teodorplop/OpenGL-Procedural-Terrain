#ifndef __COLOR_H__
#define __COLOR_H__

class Color {
public:
	float r, g, b, a;
	Color(float r, float g, float b, float a);

	const static Color red, blue;
};

#endif //__COLOR_H__