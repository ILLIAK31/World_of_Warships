#pragma once

#include "Game.hpp"
#include "Ship.hpp"

class Bot : public Game
{
private:
	friend class Ship;
	vector<vector<string>> sea2;
public:
	Bot();
	vector<vector<string>>& Get_vec2();
	void Add_Bot(Ship* ship, Bot* bot);
	void Random(int& num1 , int& num2 , int& num3,int& num4);
	~Bot();
};