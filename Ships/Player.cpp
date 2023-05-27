#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Player.hpp"
#include "Ship.hpp"

Player::Player():sea1(13, vector<string>(13))
{
	string pos[10] = { "A","B","C","D","E","F","G","H","I","J" };
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 13; ++j)
			sea1[i][j] = " ";
	for (int i = 2; i < 12; ++i)
	{
		sea1[0][i] = to_string(i - 1);
		sea1[i][0] = pos[i-2];
		sea1[i][1] = "|";
		sea1[i][12] = "|";
		sea1[1][i] = "-";
		sea1[12][i] = "-";
	}
}

vector<vector<string>> Player::Get_vec1()
{
	return this->sea1;
}

void Player::Add(Ship* ship){} //

Player::~Player(){}