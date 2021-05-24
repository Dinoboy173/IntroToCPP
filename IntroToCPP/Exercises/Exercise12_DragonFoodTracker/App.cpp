#include "Application.h"

#include <iostream>
#include <string>

using namespace std;

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	while (currentNumOfDragons < numOfDragons)
	{
		std::cout << "Enter a dragon's name: ";
		std::cin >> dragons[currentNumOfDragons];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Monday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][0];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Tuesday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][1];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Wednesday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][2];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Thursday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][3];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Friday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][4];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Saturday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][5];
		std::cout << std::endl;
		std::cout << "How much food was eaten on Sunday in kg? ";
		std::cin >> foodEatenInADay[currentNumOfDragons][6];
		std::cout << std::endl << std::endl;
		currentNumOfDragons += 1;
	}

	std::cout << "|name | mon | tue | wed | tur | fri | sat | sun |\n";
	std::cout << "| --- | --- | --- | --- | --- | --- | --- | --- |\n";
	std::cout << "| " << dragons[0] << " | " << foodEatenInADay[0][(int)Days::MONDAY] << " | " << foodEatenInADay[0][(int)Days::TUESDAY] << " | " << foodEatenInADay[0][(int)Days::WEDNESDAY] << " | " << foodEatenInADay[0][(int)Days::THURSDAY] << " | " << foodEatenInADay[0][(int)Days::FRIDAY] << " | " << foodEatenInADay[0][(int)Days::SATURDAY] << " | " << foodEatenInADay[0][(int)Days::SUNDAY] << " |\n";
	std::cout << "| " << dragons[1] << " | " << foodEatenInADay[1][(int)Days::MONDAY] << " | " << foodEatenInADay[1][(int)Days::TUESDAY] << " | " << foodEatenInADay[1][(int)Days::WEDNESDAY] << " | " << foodEatenInADay[1][(int)Days::THURSDAY] << " | " << foodEatenInADay[1][(int)Days::FRIDAY] << " | " << foodEatenInADay[1][(int)Days::SATURDAY] << " | " << foodEatenInADay[1][(int)Days::SUNDAY] << " |\n";
	std::cout << "| " << dragons[2] << " | " << foodEatenInADay[2][(int)Days::MONDAY] << " | " << foodEatenInADay[2][(int)Days::TUESDAY] << " | " << foodEatenInADay[2][(int)Days::WEDNESDAY] << " | " << foodEatenInADay[2][(int)Days::THURSDAY] << " | " << foodEatenInADay[2][(int)Days::FRIDAY] << " | " << foodEatenInADay[2][(int)Days::SATURDAY] << " | " << foodEatenInADay[2][(int)Days::SUNDAY] << " |\n";
	std::cout << std::endl;

	for (int i = 0; i < numOfDragons; i++)
	{
		std::cout << dragons[i] << ": Average food per day: " << AverageFoodEaten(i) << std::endl;
	}

	std::cout << std::endl;

	int mostEaten = MostEaten();
	int whoAteMost = WhoAteMost(mostEaten);
	string mostEatenOnDay = MostEatenOnDay(whoAteMost, mostEaten);

	int leastEaten = LeastEaten();
	int whoAteLeast = WhoAteLeast(leastEaten);
	string leastEatenOnDay = LeastEatenOnDay(whoAteLeast, leastEaten);

	std::cout << "Max: " << dragons[whoAteMost] << " ate " << mostEaten << " kg's on " << mostEatenOnDay << std::endl << std::endl;

	std::cout << "Min: " << dragons[whoAteLeast] << " ate " << leastEaten << " kg's on " << leastEatenOnDay << std::endl << std::endl;
}

int Application::AverageFoodEaten(int dragon)
{
	int average = 0;

	for (int i = 0; i < numOfDays; i++)
	{
		average += foodEatenInADay[dragon][i];
	}

	return average;
}

int Application::WhoAteMost(int mostEaten)
{
	for (int i = 0; i < numOfDragons; i++)
	{
		for (int j = 0; j < numOfDays; j++)
		{
			if (foodEatenInADay[i][j] == mostEaten)
			{
				return i;
			}
		}
	}

}

int Application::MostEaten()
{
	int mostEaten = 0;

	for (int i = 0; i < numOfDragons; i++)
	{
		for (int j = 0; j < numOfDays; j++)
		{
			if (foodEatenInADay[i][j] > mostEaten)
			{
				mostEaten = foodEatenInADay[i][j];
			}
		}
	}

	return mostEaten;
}

string Application::MostEatenOnDay(int whoAteMost, int mostEaten)
{
	for (int i = 0; i < numOfDays; i++)
	{
		if (foodEatenInADay[whoAteMost][i] == mostEaten)
		{
			switch (i)
			{
			case (int)Days::MONDAY:
				return "Monday";
			case (int)Days::TUESDAY:
				return "Tuesday";
			case (int)Days::WEDNESDAY:
				return "Wednesday";
			case (int)Days::THURSDAY:
				return "Thursday";
			case (int)Days::FRIDAY:
				return "Friday";
			case (int)Days::SATURDAY:
				return "Saturday";
			case (int)Days::SUNDAY:
				return "Sunday";
			}
		}
	}

	return "Day Not Found";
}

int Application::WhoAteLeast(int leastEaten)
{
	for (int i = 0; i < numOfDragons; i++)
	{
		for (int j = 0; j < numOfDays; j++)
		{
			if (foodEatenInADay[i][j] == leastEaten)
			{
				return i;
			}
		}
	}
}

int Application::LeastEaten()
{
	int leastEaten = INT16_MAX;

	for (int i = 0; i < numOfDragons; i++)
	{
		for (int j = 0; j < numOfDays; j++)
		{
			if (foodEatenInADay[i][j] < leastEaten)
			{
				leastEaten = foodEatenInADay[i][j];
			}
		}
	}

	return leastEaten;
}

string Application::LeastEatenOnDay(int whoAteLeast, int leastEaten)
{
	for (int i = 0; i < numOfDays; i++)
	{
		if (foodEatenInADay[whoAteLeast][i] == leastEaten)
		{
			switch (i)
			{
			case (int)Days::MONDAY:
				return "Monday";
			case (int)Days::TUESDAY:
				return "Tuesday";
			case (int)Days::WEDNESDAY:
				return "Wednesday";
			case (int)Days::THURSDAY:
				return "Thursday";
			case (int)Days::FRIDAY:
				return "Friday";
			case (int)Days::SATURDAY:
				return "Saturday";
			case (int)Days::SUNDAY:
				return "Sunday";
			}
		}
	}

	return "Day Not Found";
}