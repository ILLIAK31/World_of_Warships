#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship.hpp"

Ship::Ship(const string color,const string rotation,const string symbol):rotation(rotation),symbol(symbol)
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
}

void Ship::Add_Ship(){}

Ship::~Ship(){}