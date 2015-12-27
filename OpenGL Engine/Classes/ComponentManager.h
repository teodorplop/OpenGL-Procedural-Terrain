#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include <vector>
#include <unordered_set>
#include "GameObject.h"

class ComponentManager {
private:
	static ComponentManager* instance;

	std::unordered_set<Component*> objects;
public:
	static void Start();
	static void RegisterObject(Component* obj);
	static void UnregisterObject(Component* obj);

	static void Update();
	static void CleanUp();
};

#endif//__OBJECT_MANAGER_H__