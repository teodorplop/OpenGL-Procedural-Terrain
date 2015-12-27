#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class GameObject;

class Component {
	friend class ComponentManager;
	friend class GameObject;
public:
	Component();
	virtual ~Component();
	GameObject* GetGameObject();
protected:
	GameObject* gameObject;
	virtual void Update();
};

#endif // __COMPONENT_H__