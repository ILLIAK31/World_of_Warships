#pragma once

#include "Ship.hpp"

class Ship_4x : public Ship
{
private:
	string pos1, pos2, pos3, pos4;
public:
	Ship_4x(const string color,const string rotation,const string symbol,const int x, const char y);
	void Add_Ship(Ship* ship,Player* player)override;
	~Ship_4x();
};