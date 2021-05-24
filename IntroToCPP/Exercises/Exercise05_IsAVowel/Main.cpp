#include <iostream>
#include <cstring>

// TODO: Create the Is A Vowel method here

bool IsAVowel(char vowel)
{
    if (vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U' || vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u')
    {
        return true;
    }
    else
        return false;
}

int main(int argc, char** argv)
{
    std::cout << "Enter a letter: ";

    char vowelEntered;

    std::cin >> vowelEntered;

    if (IsAVowel(vowelEntered))
    {
        std::cout << "Is a vowel";
    }
    else
    {
        std::cout << "Not a vowel";
    }

    return 0;
}