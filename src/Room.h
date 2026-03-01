#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include <string>

class Exit;

class Room : public Entity
{
public:
	Room(const std::string& aName, const std::string& aDescription, const bool aLocked);
	~Room() override;

	void Update() override;
	void Describe() const override;

	void Look();
	Exit* GetExit(const std::string& aDirection);
	void AddExit(Exit* aExit);

	bool GetIsLocked();
	void SetIsLocked(const bool aLocked);

private:
	std::list<Exit*> mExits;
	bool mLocked;
};

#endif