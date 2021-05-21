#include "Application.h"

#include <iostream>
#include <string>

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	std::cout << CheckWinner(board0, 'x') << std::endl;
	std::cout << CheckWinner(board0, 'o') << std::endl;
	std::cout << CheckWinner(board1, 'x') << std::endl;
	std::cout << CheckWinner(board1, 'o') << std::endl;
	std::cout << CheckWinner(board2, 'x') << std::endl;
	std::cout << CheckWinner(board2, 'o') << std::endl;
	std::cout << CheckWinner(board3, 'x') << std::endl;
	std::cout << CheckWinner(board3, 'o') << std::endl;
	std::cout << CheckWinner(board4, 'x') << std::endl;
	std::cout << CheckWinner(board4, 'o') << std::endl;
}

std::string Application::CheckWinner(char board[3][3], char token)
{
    for (int i = 0; i <= 2;)
    {
        if (board[i][0] == token && board[i][1] == token && board[i][2] == token || board[0][i] == token && board[1][i] == token && board[2][i] == token)
        {
            return CheckPlayer(token);
        }

        i++;
    }

    for (int i = 0; i <= 2;)
    {
        if (board[1][1] == token && board[0 + i][0] == token && board[2 - i][2] == token)
        {
            return CheckPlayer(token);
        }

        i = i + 2;
    }

    return "No Winner";
}

std::string Application::CheckPlayer(char token)
{
    if (token == 'x')
        return "x Wins";
    else
        return "o Wins";
}