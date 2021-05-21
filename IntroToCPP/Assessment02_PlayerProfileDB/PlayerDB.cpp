#include <iostream>
#include <fstream>
#include "PlayerDB.h"
#include "Player.h"
#include <string.h>
#include <stdio.h>

void PlayerDB::Add(const char* name, int score)
{
    Player newPlayer(name, score);

    Player* temp = new Player[m_count + 1];

    for (int i = 0; i < m_count; i++)
    {
        temp[i] = m_records[i];
    }

    temp[m_count] = newPlayer;

    delete[] m_records;
    m_records = temp;
    m_count += 1;
}

bool PlayerDB::Remove(Player player)
{
    Player* temp = new Player[m_count - 1];
    int tempCount = 0;

    for (int i = 0; i < m_count; i++)
    {
        if (!(strcmp(m_records[i].name, player.name) == 0 && m_records[i].score == player.score))
        {
            temp[tempCount] = m_records[i];
            tempCount += 1;
        }
    }

    if (tempCount != m_count)
    {
        delete[] m_records;
        m_records = temp;
        m_count = tempCount;
        return true;
    }
    else
    {
        return false;
    }
}

Player PlayerDB::GetByName(const char* player, int count)
{
    if (strcmp(m_records[count].name, player) == 0)
    {
        return m_records[count];
    }

    return NULL;
}

Player PlayerDB::GetByScore(int score, int count)
{
    if (m_records[count].score == score)
    {
        return m_records[count];
    }

    return NULL;
}

bool PlayerDB::UpdatePlayers(Player currentPlayer, Player newPlayer)
{
    for (int i = 0; i < m_count; i++)
    {
        if (strcmp(m_records[i].name, currentPlayer.name) == 0 && m_records[i].score == currentPlayer.score)
        {
            m_records[i] = newPlayer;
            return true;
        }
    }

    return false;
}

bool PlayerDB::Sort(const char* sortBy)
{
    if (strcmp(sortBy, "names") == 0)
    {
        Player* temp = new Player[1];

        for (int i = 0; i < m_count - 1; i++)
        {
            for (int j = 0; j < m_count - i - 1; j++)
            {
                if (m_records[j].name[0] == m_records[j + 1].name[0])
                {
                    if ((int)m_records[j].name[1] > (int)m_records[j + 1].name[1])
                    {
                        Swap(j, j + 1);
                    }
                }

                if ((int)m_records[j].name[0] > (int)m_records[j + 1].name[0])
                {
                    Swap(j, j + 1);
                }
            }
        }

        return true;
    }
    else if (strcmp(sortBy, "scores") == 0)
    {
        Player* temp = new Player[1];

        for (int i = 0; i < m_count - 1; i++)
        {
            for (int j = 0; j < m_count - i - 1; j++)
            {
                if (m_records[j].score > m_records[j + 1].score)
                {
                    Swap(j, j + 1);
                }
            }
        }

        return true;
    }
    else
        return false;
}

void PlayerDB::Save(const char* filename)
{
    file.open(filename, std::ios_base::out | std::ios_base::binary);

    if (file.is_open())
    {
        file.write((char*)&m_count, sizeof(int));

        file.write((char*)m_records, sizeof(Player) * m_count);

        file.close();
    }
}

void PlayerDB::Load(const char* filename)
{
    file.open(filename, std::ios_base::in | std::ios_base::binary);

    if (file.is_open())
    {
        file.read((char*)&m_count, sizeof(int));

        m_records = new Player[m_count];

        file.read((char*)m_records, sizeof(Player) * m_count);

        file.close();
    }
}

void PlayerDB::Clear(const char* filename)
{
    file.open(filename, std::ios_base::out | std::ios_base::binary);

    if (file.is_open())
    {
        file.clear();

        m_count = 0;

        file.close();
    }
}

Player PlayerDB::GetHighScore()
{
    Player* temp = new Player[1];
    temp[0] = m_records[0];

    for (int i = 0; i < m_count; i++)
    {
        if (m_records[i].score > temp[0].score)
        {
            temp[0] = m_records[i];
        }
    }

    return temp[0];
}

Player PlayerDB::ShowAllPlayers(int count)
{
    return m_records[count];
}

void PlayerDB::Swap(int player1, int player2)
{
    Player temp;

    temp = m_records[player1];
    m_records[player1] = m_records[player2];
    m_records[player2] = temp;
}