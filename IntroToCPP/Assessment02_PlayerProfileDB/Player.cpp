#include "Player.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>

Player::Player()
{
    strcpy_s(name, "");

    score = 0;
}

Player::Player(const char* name, int score)
{
    strcpy_s(this->name, name);

    this->score = score;
}

Player::Player(int nullReturn)
{
    strcpy_s(this->name, "");

    this->score = NULL;
}

Player::~Player()
{

}