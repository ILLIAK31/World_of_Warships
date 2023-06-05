#pragma once

#include "Game.hpp"
#include "Ship.hpp"

class Bot : public Game
{
private:
	friend class Ship;
	vector<vector<string>> sea2;
	static int count_player_ship2;
public:
	Bot();
	vector<vector<string>>& Get_vec2();
	void Add_Bot(Ship* ship, Bot* bot);
	void Random(int& num1 , int& num2 , int& num3,int& num4);
	int& Get_Count2();
	void Print(vector<Ship*> data2);
	bool Bot_Go(Player* player, vector<Ship*>& data1, vector<Ship*>& data2);
	void Random_xy(int& num1,int& num2);
	bool Check(Player* player, const int x, const int y);
	Bot& operator=(const int x);
	~Bot();
};