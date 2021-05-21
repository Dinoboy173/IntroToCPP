#include <iostream>

int main(int argc, char** argv)
{
	// TODO: output the size in bytes of the following variables
	// Primitive Types
	/*
		int
		long int
		unsigned int
		unsigned long int
		char
		unsigned char
		float
		double
		loong double
		bool
	*/
	std::cout << "Size of a int: " << sizeof(int) << std::endl;
	std::cout << "Size of a long int: " << sizeof(long int) << std::endl;
	std::cout << "Size of a unsigned int: " << sizeof(unsigned int) << std::endl;
	std::cout << "Size of a unsigned long int: " << sizeof(unsigned long int) << std::endl;
	std::cout << "Size of a char: " << sizeof(char) << std::endl;
	std::cout << "Size of a unsigned char: " << sizeof(unsigned char) << std::endl;
	std::cout << "Size of a float: " << sizeof(float) << std::endl;
	std::cout << "Size of a double: " << sizeof(double) << std::endl;
	std::cout << "Size of a long double: " << sizeof(long double) << std::endl;
	std::cout << "Size of a boolean: " << sizeof(bool) << std::endl;

	return 0;
}