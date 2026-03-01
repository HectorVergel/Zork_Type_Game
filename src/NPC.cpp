#include <iostream>
#include "NPC.h"

NPC::NPC(const std::string& aName, const std::string aDescription, Room* aStartingRoom, Item* aItem = nullptr) :
	Entity(aName, aDescription, aStartingRoom),
	mDialogIndex(0),
	mQuestItem(aItem),
	mLastQuestState(false)
{
	// -- DIALOG WITHOUT QUEST COMPLETED --
	mDialogsNoCompleted.push_back("Hello friend! I need your help...");
	mDialogsNoCompleted.push_back("Someone stole my lucky amulet while I was sleeping on my tent...");
	mDialogsNoCompleted.push_back("I'll be very thankful if you could go find it.");

	// -- DIALOG WITH QUEST COMPLETED --
	mDialogsCompleted.push_back("Oh ho! There you go...");
	mDialogsCompleted.push_back("You really saved my day, thank you!");
}

void NPC::Describe() const
{
	std::cout << mName << std::endl;
	std::cout << mDescription << std::endl;
}

void NPC::Dialog(const bool aIsQuestCompleted)
{
	if(mLastQuestState != aIsQuestCompleted)
	{
		mDialogIndex = 0;
	}
	std::vector<std::string> CurrentDialog;
	
	CurrentDialog = aIsQuestCompleted ? mDialogsCompleted : mDialogsNoCompleted;
	std::cout << CurrentDialog[mDialogIndex] << std::endl;
	mDialogIndex++;

	if(mDialogIndex >= CurrentDialog.size())
	{
		mDialogIndex = 0;
	}

	mLastQuestState = aIsQuestCompleted;
}

std::string NPC::GetQuestItem() const
{
	return mQuestItem->GetName();
}
