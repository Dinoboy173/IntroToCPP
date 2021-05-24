#pragma once

#include "Dragon.h"

class Application
{
public:

	Application();
	~Application();

	void Run();

	void SaveToFile(const char* filename);
	void LoadFromFile(const char* filename);

protected:

	static const int NUM_DRAGONS = 5;
	Dragon m_dragons[NUM_DRAGONS];

private:
};