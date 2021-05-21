#include "Application.h"
#include "Dragon.h"
#include <iostream>
#include <fstream>

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
	const char* filename = "data.dat";

	m_dragons[0] = Dragon("fluffy");
	m_dragons[1] = Dragon("bunny");
	m_dragons[2] = Dragon("kittens");
	m_dragons[3] = Dragon("spike");
	m_dragons[4] = Dragon("bob");

	// save the above numbers to file
	SaveToFile(filename);

	m_dragons[0] = Dragon();
	m_dragons[1] = Dragon();
	m_dragons[2] = Dragon();
	m_dragons[3] = Dragon();
	m_dragons[4] = Dragon();

	LoadFromFile(filename);

	for (int i = 0; i < NUM_DRAGONS; i++)
	{
		m_dragons[i].Print();
	}
}

void Application::SaveToFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios_base::out);

	if (file.is_open())
	{
		for (int i = 0; i < NUM_DRAGONS; i++)
		{
			file.write((char*)&m_dragons[i], sizeof(Dragon));
		}

		file.close();
	}
}

void Application::LoadFromFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios_base::in);

	if (file.is_open())
	{
		for (int i = 0; i < NUM_DRAGONS; i++)
		{
			file.read((char*)&m_dragons[i], sizeof(Dragon));
		}

		file.close();
	}
}