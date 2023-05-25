#pragma once

#include "Game.hpp"

class Player : public Game
{
private:
	vector<vector<string>> sea1;
public:
	Player();
	~Player();
};