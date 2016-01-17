#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class GameObject;

class Component {
	friend class ComponentManager;
	friend class GameObject;
private:
	bool isActive;
public:
	Component();
	virtual ~Component();
	GameObject* GetGameObject();
	bool IsActive();
	void SetActive(bool isActive);
protected:
	GameObject* gameObject;
	virtual void Update();
};

#endif // __COMPONENT_H__