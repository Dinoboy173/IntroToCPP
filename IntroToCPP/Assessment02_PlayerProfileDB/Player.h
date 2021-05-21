#pragma once

class Player
{
public:

    char name[32];
    int score;

public:

    Player();
    Player(const char* name, int score);
    Player(int nullReturn);
    ~Player();

protected:
private:
};