#pragma once

#include <string>

class Dragn
{
public:

	std::string name;

	static const int DAYS_PER_WEEK = 7;
	int foodEatenPerDay[DAYS_PER_WEEK];

public:

	// default constructor
	Dragn();

	// overloaded constructor
	Dragn(const char* name);

	// destructor
	~Dragn();

	void Print();
};

