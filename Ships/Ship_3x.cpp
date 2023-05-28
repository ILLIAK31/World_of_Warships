#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship_3x.hpp"

Ship_3x::Ship_3x(const string symbol, const string rotation, const string color, const int x, const char y):Ship(symbol, rotation, color, x, y) {}

void Ship_3x::Add_Ship(Ship* ship, Player* player)
{
	//
}

Ship_3x::~Ship_3x(){}