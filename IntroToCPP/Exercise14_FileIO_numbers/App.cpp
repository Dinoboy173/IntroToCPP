#include "Application.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
	const char* filename = "data.dat";

	srand(time(0)); // fix

	num1 = rand() % 1000;
	num2 = rand() % 1000;
	num3 = rand() % 1000;
	num4 = rand() % 1000;
	num5 = rand() % 1000;
	num6 = rand() % 1000;

	// save the above numbers to file
	SaveToFile(filename);

	// reset the numbers
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	num5 = 0;
	num6 = 0;

	LoadFromFile(filename);

	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;
	std::cout << num4 << std::endl;
	std::cout << num5 << std::endl;
	std::cout << num6 << std::endl;
}

void Application::SaveToFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios_base::out | std::ios_base::binary);

	if (file.is_open())
	{
		file.write((char*)&num1, sizeof(int));
		file.write((char*)&num2, sizeof(int));
		file.write((char*)&num3, sizeof(float));
		file.write((char*)&num4, sizeof(float));
		file.write((char*)&num5, sizeof(double));
		file.write((char*)&num6, sizeof(double));
	}

	file.close();
}

void Application::LoadFromFile(const char* filename)
{
	// TODO: write your code here
	std::fstream file;
	file.open(filename, std::ios_base::in | std::ios_base::binary);

	if (file.is_open())
	{
		file.read((char*)&num1, sizeof(int));
		file.read((char*)&num2, sizeof(int));
		file.read((char*)&num3, sizeof(float));
		file.read((char*)&num4, sizeof(float));
		file.read((char*)&num5, sizeof(double));
		file.read((char*)&num6, sizeof(double));
	}

	file.close();
}