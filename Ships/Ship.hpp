#pragma once

#include "Player.hpp"
#include "Bot.hpp"

class Ship
{
private:
	string color , rotation , symbol;
public:
	Ship(const string color,const string rotation,const string symbol);
	virtual void Add_Ship();
	~Ship();
};