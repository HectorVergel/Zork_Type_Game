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
	std::cout << "Item: " << mName << std::endl;
	std::cout << mDescription << std::endl;
}
