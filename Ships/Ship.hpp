#pragma once

#include "Player.hpp"
#include "Bot.hpp"

class Ship : public Player , public Bot
{
private:
	string color , rotation;
public:
};