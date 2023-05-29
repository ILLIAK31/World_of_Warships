#pragma once

#include "Ship.hpp"

class Ship_3x : public Ship
{
public:
	string pos[3];
public:
	Ship_3x(const string symbol, const string rotation, const string color, const int x, const char y);
	void Add_Ship(Ship* ship, Player* player)override;
	~Ship_3x();
};