#ifndef __SCENE_H__
#define __SCENE_H__

#include "Homework\Circle.h"

class Scene {
private:
	Circle *circle, *circle2, *circle3;

public:
	Scene();
	~Scene();
	void Start();
	void Update();
};

#endif//__SCENE_H__