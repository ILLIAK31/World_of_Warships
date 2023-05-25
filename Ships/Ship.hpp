#pragma once

#include "Player.hpp"
#include "Bot.hpp"

class Ship : public Player , public Bot
{
	friend class Player;
private:
	string color , rotation , symbol;
public:
	Ship(string color, string rotation,string symbol);
	~Ship();
};