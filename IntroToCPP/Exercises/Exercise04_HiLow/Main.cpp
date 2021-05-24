#include <iostream>
#include <stdlib.h>
#include <time.h>   

int main(int argc, char** argv)
{
	unsigned int guess = 0;

	srand(time(NULL));
	int rand1 = rand() % 99 + 1;

	bool right = false;

	std::cout << "Guess a number between 0 and 100: ";
	std::cin >> guess;

	do // redo all of this
		(
			if (guess > rand1)
			{
				std::cout << "Lower, have another guess: ";
				std::cin >> guess;
			}
			else if (guess < rand1)
			{
				std::cout << "Higher, have another guess: ";
				std::cin >> guess;
			}
			else if (guess == rand1)
			{
				std::cout << "Correct";
				right = true;
			}
	);
	while (!right);

	return 0;
}