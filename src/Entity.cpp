#include "Entity.h"
#include "Utils.h"

Entity::Entity(const std::string& aName, const std::string& aDescription, Entity* aParent) :
	mName(aName),
	mDescription(aDescription),
	mParent(aParent)
{
	if(mParent != nullptr)
	{
		mParent->mContains.push_back(this);
	}

}

Entity::~Entity()
{
	SAFE_DELETE_VECTOR(mContains);
}

void Entity::Describe() const
{
}

bool Entity::IsStorage() const
{
	return false;
}

std::string Entity::GetName() const
{
	return mName;
}

bool Entity::Add(Entity* aEntity)
{
	if(aEntity == nullptr)
	{
		return false;
	}
	mContains.push_back(aEntity);
	aEntity->SetParent(this);
	return true;
}

bool Entity::Remove(Entity* aEntity)
{
	if(aEntity == nullptr)
	{
		return false;
	}
	auto Iterator = std::find(mContains.begin(), mContains.end(), aEntity);
	if(Iterator != mContains.end())
	{
		mContains.erase(Iterator);
		aEntity->SetParent(nullptr);
		return true;
	}
	return false;
}

Entity* Entity::Find(const std::string& aEntityName)
{
	for(const auto Entity : mContains)
	{
		if(Entity->GetName().compare(aEntityName) == 0)
		{
			return Entity;
		}
	}
	return nullptr;
}

void Entity::SetParent(Entity* aParent)
{
	mParent = aParent;
}

Entity* Entity::GetParent()
{
	return mParent;
}

std::list<Entity*> Entity::GetContains()
{
	return mContains;
}
