#ifndef NPC_H
#define NPC_H

#include <vector>
#include "Entity.h"
#include "Room.h"
#include "Item.h"

class NPC : public Entity
{
public:
	NPC(const std::string& aName, const std::string aDescription, Room* aStartingRoom, Item* aItem);
	~NPC() override = default;

	void Describe() const override;
	void Dialog(const bool aIsQuestCompleted);
	std::string GetQuestItem() const;

private:

	std::vector<std::string> mDialogsNoCompleted;
	std::vector<std::string> mDialogsCompleted;
	int mDialogIndex;
	Item* mQuestItem;
	bool mLastQuestState;
};

#endif