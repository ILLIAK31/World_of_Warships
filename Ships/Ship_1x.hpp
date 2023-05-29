#pragma once

#include "Ship.hpp"

class Ship_1x : public Ship
{
private:
	string pos;
public:
	Ship_1x(const string symbol, const string rotation, const string color, const int x, const char y);
	void Add_Ship(Ship* ship, Player* player)override;
	~Ship_1x();
};