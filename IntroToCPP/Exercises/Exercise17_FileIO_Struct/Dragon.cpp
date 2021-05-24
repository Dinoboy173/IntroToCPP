#include "Dragon.h"
#include <math.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>

// default constructor
Dragon::Dragon()
{
	// initialise the name as empty
	strcpy_s(name, "");

	for (int i = 0; i < DAYS_PER_WEEK; i++)
		foodEatenPerDay[i] = rand() % 100;
}

// overloaded constructor
Dragon::Dragon(const char* name)
{
	// initialise the name with the name passed in
	strcpy_s(this->name, name);

	srand(time(0));

	for (int i = 0; i < DAYS_PER_WEEK; i++)
		foodEatenPerDay[i] = rand() % 100;
}

// destructor
Dragon::~Dragon()
{

}

void Dragon::Print()
{
	std::cout << name << std::endl;

	for (int j = 0; j < DAYS_PER_WEEK; j++)
		std::cout << (int)foodEatenPerDay[j] << ", ";

	std::cout << std::endl << std::endl;
}