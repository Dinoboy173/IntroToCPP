#pragma once

#include "Dragon.h"
#include <fstream>

class App
{
public:

	App();
	~App();

	void Run();

	void SaveToFile(const char* filename);
	void LoadFromFile(const char* filename);

	void SaveDragon(std::fstream& file, const Dragn* dragon);
	void LoadDragon(std::fstream& file, Dragn* dragon);

protected:

	static const int NUM_DRAGONS = 5;
	Dragn m_dragons[NUM_DRAGONS];

private:

};
