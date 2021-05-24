#include <iostream>
#include <string>
#include "Greetings.h"

void GreetPerson(const std::string& name)
{
    std::string nameLength = NameLength(name);
    std::string numVowels = CountVowels(name);
    std::string upper = ToUpper(name);
    std::string lower = ToLower(name);
    std::string firstName = FirstName(name);
    std::string lastName = LastName(name);
    std::string reverse = Reverse(name);

    std::cout
        << "Hello " + name + "\b." << std::endl
        << "Your name is " << nameLength + " characters long." << std::endl
        << "There are " + numVowels + " vowles in your name." << std::endl
        << "Upper: " + upper << std::endl
        << "Lower: " + lower << std::endl
        << "First name: " + firstName << std::endl
        << "Last name: " + lastName << std::endl
        << "Reversed: " + reverse << std::endl << std::endl;
}

int main(int argc, char** argv)
{
    std::string names[12] = { "Charlotte Jones ", "Oliver Smith ", "Olivia Johnson ", "William Brown ", "Mia Williams ", "Jack Garcia ", "Ava Miller ", "Noah Davis ", "Amelia Wilson ", "James Anderson ", "Sofia Moore ", "Thomas Sanchez " };

    for (int i = 0; i < 12; i++)
    {
        GreetPerson(names[i]);
    }

    return 0;
}