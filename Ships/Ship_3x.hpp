#pragma once

#include "Ship.hpp"

class Ship_3x : public Ship
{
public:
	Ship_3x(const string symbol, const string rotation, const string color, const int x, const char y);
	void Add_Ship(Ship* ship, Player* player)override;
	void Add_Ship_Bot(Ship* ship, Bot* bot)override;
	//string pos[4];
	~Ship_3x();
};