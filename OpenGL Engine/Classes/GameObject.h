#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <string>
#include <unordered_map>

#include "Shader.h"
#include "Transform.h"
#include "Component.h"

class GameObject {
	friend class ComponentManager;

private:
	Transform* transform;
	std::unordered_map<std::string, Component*> components;

public:
	Transform* GetTransform();
	Component* GetComponent(std::string name);
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	void RemoveComponent(std::string name);

	GameObject();
	~GameObject();
};

#endif //__GAME_OBJECT_H__