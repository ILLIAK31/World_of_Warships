#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship.hpp"

Ship::Ship(const string symbol,const string rotation,const string color,const int x , const char y):rotation(rotation),symbol(symbol),x(x),y(y)
{
	if (color == "Red")
		this->color = "31m";
	else if (color == "Blue")
		this->color = "34m";
	else if (color == "Green")
		this->color = "32m";
	else if (color == "Yellow")
		this->color = "33m";
	else if (color == "Purple")
		this->color = "35m";
	else if (color == "White")
		this->color = "37m";
	damaged = false;
}

void Ship::Add_Ship(Ship* ship,Player* player){}

void Ship::Add_Ship_Bot(Ship* ship, Bot* bot){}

string Ship::Get_color()
{
	return this->color;
}

string Ship::Get_rotation()
{
	return this->rotation;
}

string Ship::Get_symbol()
{
	return this->symbol;
}

int Ship::Get_x()
{
	return this->x;
}

char Ship::Get_y()
{
	return this->y;
}

Ship::~Ship(){}