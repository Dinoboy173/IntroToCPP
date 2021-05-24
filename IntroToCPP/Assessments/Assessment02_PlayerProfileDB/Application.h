#pragma once

#include <string>

#include "Player.h"
#include "PlayerDB.h"

class Application
{
public:

	Application();
	~Application();

	void Run();
	void GetPlayer();
	void GetScore();

protected:

	std::string m_command;
	std::string m_command2;
	Player m_newPlayer;
	Player m_pGet;
	char m_getPlayer[32];
	int m_getScore;
	int m_getCounter = 0;
	bool m_playerRemoved;
	bool m_sorted;
	bool m_updated;

	const char* filename = "dateBase.dat";

private:

	Player nullReturn = Player("Player Doesn't Exist", 0);
};