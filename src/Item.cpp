#include "Item.h"
#include <iostream>

Item::Item(const std::string& aName, const std::string& aDescription, Entity* aParent) :
	Entity(aName, aDescription, aParent)
{
}

void Item::Update()
{
}

void Item::Describe() const
{
	std::cout << "There is an item here: " << mName << std::endl;
}
