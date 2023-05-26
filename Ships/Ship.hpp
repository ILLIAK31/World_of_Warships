#pragma once

#include "Player.hpp"
#include "Bot.hpp"

class Ship : public Player , public Bot
{
	friend class Player;
private:
	string color , rotation , symbol;
public:
	Ship(const string color,const string rotation,const string symbol);
	~Ship();
};