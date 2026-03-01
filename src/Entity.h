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
	virtual bool IsStorage() const;

	std::string GetName() const;
	virtual bool Add(Entity* aEntity);
	virtual bool Remove(Entity* aEntity);
	Entity* Find(const std::string& aEntityName);
	void SetParent(Entity* aParent);
	Entity* GetParent();
	std::list<Entity*> GetContains();


protected:
	std::string mName;
	std::string mDescription;
	std::list<Entity*> mContains;
	Entity* mParent;
};
#endif

