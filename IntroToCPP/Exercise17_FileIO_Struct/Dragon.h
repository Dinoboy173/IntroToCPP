#pragma once

class Dragon
{
public:

	char name[32];

	static const int DAYS_PER_WEEK = 7;
	int foodEatenPerDay[DAYS_PER_WEEK];

public:

	// default constructor
	Dragon();

	// overloaded constructor
	Dragon(const char* name);

	// destructor
	~Dragon();

	void Print();
};