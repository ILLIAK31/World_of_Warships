#pragma once

#include "Player.hpp"
#include "Bot.hpp"

class Ship
{
private:
	string color , rotation , symbol;
	int x;
	char y;
public:
	Ship(const string symbol,const string rotation,const string color,const int x , const char y);
	virtual void Add_Ship(Ship* ship,Player* player);
	string Get_color();
	string Get_rotation();
	string Get_symbol();
	int Get_x();
	char Get_y();
	~Ship();
};