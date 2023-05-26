#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship.hpp"

Ship::Ship(const string color,const string rotation,const string symbol):color(color),rotation(rotation),symbol(symbol){}

Ship::~Ship(){}