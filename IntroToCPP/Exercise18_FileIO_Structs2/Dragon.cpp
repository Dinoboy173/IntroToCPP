#include "Dragon.h"
#include <math.h>
#include <cstring>
#include <iostream>

// default constructor
Dragn::Dragn()
{
	// initialise the name as empty
	name = "";

	for (int i = 0; i < DAYS_PER_WEEK; i++)
		foodEatenPerDay[i] = 0;
}

// overloaded constructor
Dragn::Dragn(const char* name)
{
	// initialise the name with the name passed in
	this->name = name;

	for (int i = 0; i < DAYS_PER_WEEK; i++)
		foodEatenPerDay[i] = rand() % 100;
}

// destructor
Dragn::~Dragn()
{

}

void Dragn::Print()
{
	std::cout << name << std::endl;

	for (int j = 0; j < DAYS_PER_WEEK; j++)
		std::cout << (int)foodEatenPerDay[j] << ", ";

	std::cout << std::endl << std::endl;
}