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
	bool Player_Go(Bot* bot,vector<Ship*>& data1, vector<Ship*>& data2);
	bool Check(Bot* bot,const int x , const int y);
	void Random(Player* player,vector<Ship*>& data1);
	void Random_num(int& num1, int& num2, int& num3, int& num4);
	bool Enter_data3(Player* player, string& symbol, string& rotation, string& color, int& x, char& y, int type);
	bool Check_val_xy3(const int x, const char y, int type, const string rot, Player* player);
	~Player();
};