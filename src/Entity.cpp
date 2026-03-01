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

const std::string Entity::GetName()
{
	return mName;
}

void Entity::Add(Entity* aEntity)
{
	if(aEntity == nullptr)
	{
		return;
	}
	mContains.push_back(aEntity);
	aEntity->SetParent(this);
}

void Entity::Remove(Entity* aEntity)
{
	if(aEntity == nullptr)
	{
		return;
	}
	auto Iterator = std::find(mContains.begin(), mContains.end(), aEntity);
	if(Iterator != mContains.end())
	{
		mContains.erase(Iterator);
		aEntity->SetParent(nullptr);
	}
}

void Entity::SetParent(Entity* aParent)
{
	mParent = aParent;
}

Entity* Entity::GetParent()
{
	return mParent;
}
