#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include <string>
#include "Exit.h"

class Room : public Entity
{
public:
	Room(const std::string& aName, const std::string& aDescription, const bool aLocked);
	~Room() override = default;

	void Update() override;
	void Describe() const override;

	void Look();
	Exit* GetExit(const std::string& aDirection);
	void AddExit(Exit* aExit);

private:
	std::list<Exit*> mExits;
	bool mLocked;
};

#endif