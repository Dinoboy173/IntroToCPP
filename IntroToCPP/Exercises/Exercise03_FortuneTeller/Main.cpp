#include <iostream>
#include <cstring>

int main(int argc, char** argv)
{
    unsigned int numOfChildren = 0;
    char partner[100] = "";
    char location[100] = "";
    char jobTitle[100] = "";

    std::cout << "What's your dream job?: ";
    std::cin.getline(jobTitle, 100);

    std::cout << "Where do you want to live?: ";
    std::cin.getline(location, 100);

    std::cout << "What do you want your partners name to be?: ";
    std::cin.getline(partner, 100);

    std::cout << "How many children do you want?: ";
    std::cin >> numOfChildren;
    std::cout << "\n";

    std::cout << "You will be a " << jobTitle << " in " << location << ", and married to " << partner << " with " << numOfChildren << " kids.";

    return 0;
}