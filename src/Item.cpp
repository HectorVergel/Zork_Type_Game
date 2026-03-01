#include <iostream>
#include "Item.h"
#include "Utils.h"

Item::Item(const std::string& aName, const std::string& aDescription, Entity* aParent, const int aItemStorageSlots) :
	Entity(aName, aDescription, aParent),
	mStorageSlots(aItemStorageSlots)
{
}

Item::~Item()
{
}

void Item::Update()
{
}

void Item::Describe() const
{
	std::cout << "Item: " << mName << std::endl;
	std::cout << mDescription << std::endl;
}

bool Item::IsStorage() const
{
	return mStorageSlots > 0;
}


bool Item::Add(Entity* aEntity)
{
	if(mCurrentUsedSlots < mStorageSlots)
	{
		if (aEntity == nullptr)
		{
			return false;
		}
		mContains.push_back(aEntity);
		aEntity->SetParent(this);

		mCurrentUsedSlots++;
		return true;
	}
	return false;
}

bool Item::Remove(Entity* aEntity)
{
	if (aEntity == nullptr)
	{
		return false;
	}
	auto Iterator = std::find(mContains.begin(), mContains.end(), aEntity);
	if (Iterator != mContains.end())
	{
		mContains.erase(Iterator);
		aEntity->SetParent(nullptr);

		if(mCurrentUsedSlots > 0)
		{
			mCurrentUsedSlots--;
		}
		return true;
	}
	return false;
}

