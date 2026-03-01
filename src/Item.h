#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const std::string& aName, const std::string& aDescription, Entity* aParent = nullptr);
	~Item() override = default;

	void Update() override;
	void Describe() const override;
};

#endif