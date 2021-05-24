#include "TicTacToeGame.h"
#include "TicTacToeApp.h"
#include <string>

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::PlaceToken(char token, int pos[2])
{
    board[pos[0]][pos[1]] = token;
}

bool TicTacToe::CheckWinner(char token)
{
    for (int i = 0; i <= 2;)
    {
        if (board[i][0] == token && board[i][1] == token && board[i][2] == token || board[0][i] == token && board[1][i] == token && board[2][i] == token)
        {
            return true;
        }

        i++;
    }

    for (int i = 0; i <= 2;)
    {
        if (board[1][1] == token && board[0 + i][0] == token && board[2 - i][2] == token)
        {
            return true;
        }

        i = i + 2;
    }

    return false;
}

char TicTacToe::SwitchPlayer(char token)
{
    if (token == (char)Tokens::X)
        return (char)Tokens::O;
    else if (token == (char)Tokens::O)
        return (char)Tokens::X;
}

char TicTacToe::GetToken(int row, int col)
{
    return board[row][col];
}

void TicTacToe::SetToken(int row, int col, char val)
{
    board[row][col] = val;
}