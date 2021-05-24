#pragma once

#include <string>

using namespace std;

enum class Days
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

class Application
{
public:

    static const int numOfDragons = 3;
    static const int numOfDays = 7;
    static const int numOfLetters = 32;

    int currentNumOfDragons = 0;

    char dragons[numOfDragons][numOfLetters];

    int foodEatenInADay[numOfDragons][numOfDays];

public:

    Application();
    ~Application();

    void Run();
    int AverageFoodEaten(int dragon);

    int WhoAteMost(int mostEaten);
    int MostEaten();
    string MostEatenOnDay(int whoAteMost, int mostEaten);

    int WhoAteLeast(int leastEaten);
    int LeastEaten();
    string LeastEatenOnDay(int whoAteLeast, int leastEaten);

protected:
private:
};

