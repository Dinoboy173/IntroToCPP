#pragma once
#include "TicTacToeGame.h"

enum class GameStates
{
    MENU,
    CONTROLS,
    PLAY,
    WIN
};

enum class Controls
{
    BACK = 8,
    ENTER = 13,
    QUIT = 27,
    SELECTGAMEPOS = 32,
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};

enum class Tokens
{
    BLANK = 32,
    SELECTOR = 35,
    O = 111,
    X = 120
};


class TicTacToeApp
{
public:
    TicTacToeApp();
    ~TicTacToeApp();

    void Run();

    void RunMenuState();
    void RunControlsState();
    void RunPlayState();
    void RunWinState();

    void MenuControl();
    void MiscControl();
    void GameControl();
    
    void PlaceBlank();
    void MoveToken(int direction);

public:
    int m_selectorPos[2] = { 1, 1 };

protected:
    bool m_shouldQuit = false;
    bool invalidPlacement = false;
    int m_menuSelection = 1;
    int m_gameSelection = 0;
    bool winner = false;
    GameStates m_gameState = GameStates::MENU;

    char m_currentPlayer = (char)Tokens::X;

    //TicTacToe m_game;

private:
    int m_windowWidth = 800;
    int m_windowHeight = 450;
};