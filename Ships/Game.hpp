#pragma once

class Game
{
private:
	friend class Player;
	friend class Ship;
	static int count_ships , count_4x , count_3x , count_2x , count_x;
public:
	Game()=default;
	void Start(Player* player,vector<Ship*>& data1);
	bool Check_val_sym(const string sym);
	bool Check_val_rot(const string rot);
	bool Check_val_col(const string col);
	bool Check_val_xy(const int x, const char y,int type,const string rot, Player* player);
	bool Enter_data(Player* player,string& symbol, string& rotation, string& color,int& x, char& y,int type);
	void print(Player* player, vector<Ship*> data1);
	virtual ~Game();
};