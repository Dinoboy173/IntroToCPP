#include <iostream>

int StringLength(const char* szString)
{
	int i = 0;
	while (szString[i] != '\0')
		i++;

	return i;
}

int main(int argc, char** argv)
{
	std::cout << "Length: " << StringLength("Bannana") << std::endl;
	std::cout << "Length: " << StringLength("Apple") << std::endl;
	std::cout << "Length: " << StringLength("Mangow") << std::endl;
	std::cout << "Length: " << StringLength("Orange") << std::endl;

	return 0;
}