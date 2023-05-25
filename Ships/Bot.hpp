#pragma once

#include "Game.hpp"

class Bot : public Game
{
private:
	vector<vector<string>> sea2;
public:
	Bot();
	~Bot();
};