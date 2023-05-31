#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

#include "Bot.hpp"

Bot::Bot():sea2(13, vector<string>(13))
{
	string pos[10] = { "A","B","C","D","E","F","G","H","I","J" };
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 13; ++j)
			sea2[i][j] = " ";
	for (int i = 2; i < 12; ++i)
	{
		sea2[0][i] = to_string(i - 1);
		sea2[i][0] = pos[i - 2];
		sea2[i][1] = "|";
		sea2[i][12] = "|";
		sea2[1][i] = "-";
		sea2[12][i] = "-";
	}
}

vector<vector<string>>& Bot::Get_vec2()
{
	return this->sea2;
}

void Bot::Add_Bot(Ship* ship, Bot* bot)
{
	ship->Add_Ship_Bot(ship, bot);
}

void Bot::Random(int& num1, int& num2, int& num3, int& num4)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(1, 10);
	uniform_int_distribution<int> distribution2(1, 6);
	uniform_int_distribution<int> distribution3(1, 2);
	num1 = distribution(generator);
	num2 = distribution(generator);
	num3 = distribution2(generator);
	num4 = distribution3(generator);
}

int& Bot::Get_Count2()
{
	return this->count_player_ship2;
}

Bot::~Bot()
{
	for (auto& row : sea2)
		row.clear();
	sea2.clear();
}