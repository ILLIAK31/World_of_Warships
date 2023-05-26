#pragma once

class Game
{
private:
	static int count_ships , count_4x , count_3x , count_2x , count_x;
public:
	Game()=default;
	void Start();
	bool Check_val_sym(const string sym);
	bool Check_val_rot(const string rot);
	bool Check_val_col(const string col);
	bool Check_val_xy(const int x, const char y,int type,const string rot);
	virtual ~Game();
};