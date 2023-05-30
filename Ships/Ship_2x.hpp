#pragma once

#include "Ship.hpp"

class Ship_2x : public Ship
{
private:
	string pos[2];
public:
	Ship_2x(const string symbol, const string rotation, const string color, const int x, const char y);
	void Add_Ship(Ship* ship, Player* player)override;
	void Add_Ship_Bot(Ship* ship, Bot* bot)override;
	~Ship_2x();
};