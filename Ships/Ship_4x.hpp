#pragma once

#include "Ship.hpp"

class Ship_4x : public Ship
{
private:
public:
	Ship_4x(const string color,const string rotation,const string symbol);
	void Add_Ship()override;
	~Ship_4x();
};