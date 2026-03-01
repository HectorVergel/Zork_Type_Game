#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "Entity.h"
class Item : public Entity
{
public:
	Item(const std::string& aName, const std::string& aDescription, Entity* aParent = nullptr, const int aStorageSlots = 0);
	~Item() override;

	void Update() override;
	void Describe() const override;
	bool IsStorage() const override;
	bool Add(Entity* aEntity) override;
	bool Remove(Entity* aEntity) override;
	
private:
	int mStorageSlots;
	int mCurrentUsedSlots;
};

#endif