#ifndef GAME_H
#define GAME_H

#include <string>
#include "World.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	void ProcessCommand(const std::string& aInput);
	void PrintHelp();

	World* mWorld;
	bool mRunning;
};

#endif

