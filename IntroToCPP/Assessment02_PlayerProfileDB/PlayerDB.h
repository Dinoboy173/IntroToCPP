#pragma once

#include <fstream>
#include "Player.h"
#include "Application.h"

class PlayerDB
{
public:

    void Add(const char* name, int score);
    bool Remove(Player player);
    Player GetByName(const char* player, int count);
    Player GetByScore(int score, int count);
    bool UpdatePlayers(Player currentPlayer, Player newPlayer);
    bool Sort(const char* sortBy);
    void Save(const char* filename);
    void Load(const char* filename);
    void Clear(const char* filename);
    Player GetHighScore();
    Player ShowAllPlayers(int count);
    void Swap(int player1, int player2);

    int m_count = 0;

protected:

    Player* m_records = nullptr;
    std::fstream file;

private:
};