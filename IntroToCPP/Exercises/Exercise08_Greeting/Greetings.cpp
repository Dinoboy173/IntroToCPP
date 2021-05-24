#include <iostream>
#include <string>

std::string NameLength(const std::string& name)
{
    int spaceCount = 0;
    for (int i = 0; i < name.length(); i++)
        if (name[i] == ' ') spaceCount++;

    return std::to_string(name.length() - spaceCount);
}

std::string CountVowels(const std::string& name)
{
    int vowelCount = 0;
    for (int i = 0; i < name.length(); i++)
        if (std::tolower(name[i]) == 'a') vowelCount++;
        else if (std::tolower(name[i]) == 'e') vowelCount++;
        else if (std::tolower(name[i]) == 'i') vowelCount++;
        else if (std::tolower(name[i]) == 'o') vowelCount++;
        else if (std::tolower(name[i]) == 'u') vowelCount++;
    return std::to_string(vowelCount);
}

std::string ToUpper(const std::string& name)
{
    std::string upper = "";
    for (int i = 0; i < name.length(); i++)
        upper += std::toupper(name[i]);
    return upper;
}

std::string ToLower(const std::string& name)
{
    std::string lower = "";
    for (int i = 0; i < name.length(); i++)
        lower += std::tolower(name[i]);
    return lower;
}

std::string FirstName(const std::string& name)
{
    std::string firstName = "";
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ') return firstName;
        firstName += name[i];
    }
    return 0;
}

std::string LastName(const std::string& name)
{
    int startingPoint = 1;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ') break;
        startingPoint += 1;
    }

    std::string lastName = "";
    for (int i = startingPoint; i < name.length(); i++)
    {
        if (name[i] == ' ') return lastName;
        lastName += name[i];
    }
    return 0;
}

std::string Reverse(const std::string& name)
{
    std::string reversed = "\b";
    for (int i = name.length(); i > -1; i--)
    {
        reversed += name[i];
    }
    return reversed;
}