#pragma once

#include "Game.hpp"
#include "Ship.hpp"

class Player : public Game
{
private:
	friend class Ship;
	vector<vector<string>> sea1;
	static int count_player_ship;
public:
	Player();
	vector<vector<string>>& Get_vec1();
	void Add(Ship* ship,Player* player);
	int& Get_Count();
	void Print(vector<Ship*> data1);
	bool Player_Go(vector<Ship*>& data1, vector<Ship*>& data2);
	~Player();
};