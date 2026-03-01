#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>

class Entity
{
public:
	Entity(const std::string& aName, const std::string& aDescription, Entity* aParent);
	virtual ~Entity();
	virtual void Update() = 0;
	virtual void Describe() const;

	const std::string GetName();
	void Add(Entity* aEntity);
	void Remove(Entity* aEntity);
	void SetParent(Entity* aParent);
	Entity* GetParent();


protected:
	std::string mName;
	std::string mDescription;
	std::list<Entity*> mContains;
	Entity* mParent;
};
#endif

