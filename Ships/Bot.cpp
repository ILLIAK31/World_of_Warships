#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

#include "Bot.hpp"

Bot::Bot():sea2(13, vector<string>(13)){}

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

Bot::~Bot(){}