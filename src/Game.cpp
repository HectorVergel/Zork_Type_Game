#include <iostream>
#include <sstream>
#include "Game.h"
#include "Utils.h"

Game::Game() :
	mWorld(nullptr),
	mPlayer(nullptr),
	mRunning(true)
{
}

Game::~Game()
{
	SAFE_DELETE(mWorld);
}

void Game::Run()
{
	std::cout << "Welcome to my Zork! game implementation!" << std::endl;
	std::cout << "Type 'help' for commands." << std::endl;

	mPlayer->Look();

	while(mRunning)
	{
		std::cout << "\n> ";

		std::string Input;
		std::getline(std::cin, Input);

		ProcessCommand(Input);
		mPlayer->Update();
	}
}

void Game::ProcessCommand(const std::string& aInput)
{
    std::istringstream Iss(aInput);

    std::string Command;
    Iss >> Command;

    if (Command == "look")
    {
        mPlayer->Look();
    }
    else if (Command == "go")
    {
        std::string Direction;
        Iss >> Direction;

        if (Direction.empty())
            std::cout << "Go where?\n";
        else
            mPlayer->Move(Direction);
    }
    else if (Command == "take")
    {
        std::string Item;
        Iss >> Item;

        if (Item.empty())
            std::cout << "Take what?\n";
        else
            mPlayer->Take(Item);
    }
    else if (Command == "drop")
    {
        std::string Item;
        Iss >> Item;

        if (Item.empty())
            std::cout << "Drop what?\n";
        else
            mPlayer->Drop(Item);
    }
    else if (Command == "help")
    {
        PrintHelp();
    }
    else if (Command == "quit")
    {
        mRunning = false;
        std::cout << "Goodbye!\n";
    }
    else
    {
        std::cout << "I don't understand that command.\n";
    }
}

void Game::PrintHelp()
{
    std::cout << "You can use the following commands: " << std::endl;
    std::cout << "'look' command for investigating \n" << 
        "'go (direction)' for moving \n" << 
        "'take (item name)' for taking items \n" << 
        "'drop (item name)' for dropping items \n" << 
        "'quit' fot finishing the game";
}
