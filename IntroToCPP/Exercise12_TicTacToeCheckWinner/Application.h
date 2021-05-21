#pragma once

#include <string>

class Application
{
public:

	Application();
	~Application();

	void Run();
	std::string CheckWinner(char board[3][3], char token);
	std::string CheckPlayer(char token);

protected:
private:

	char board0[3][3] =
	{
		{'x', ' ', ' '},
		{' ', 'x', ' '},
		{' ', ' ', 'x'}
	};

	char board1[3][3] =
	{
		{' ', 'o', ' '},
		{' ', 'o', ' '},
		{' ', 'o', ' '}
	};

	char board2[3][3] =
	{
		{' ', 'o', ' '},
		{'x', 'x', 'x'},
		{' ', 'o', ' '}
	};

	char board3[3][3] =
	{
		{'x', 'o', 'o'},
		{'x', 'o', 'x'},
		{'o', 'x', 'x'}
	};
	char board4[3][3] =
	{
		{'o', 'o', 'x'},
		{'x', 'x', 'o'},
		{'o', 'x', 'x'}
	};

};