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

void Bot::Print(vector<Ship*> data2)
{
	int x = 0, y = 0, index;
	string colors[2] = { "\033[46m","\033[100m" };
	cout << endl;
	for_each(this->Get_vec2().begin(), this->Get_vec2().end(), [data2, &x, &y, &index, &colors](const vector<string>& row) {for_each(row.begin(), row.end(), [data2, &x, &y, &index, &colors](const string& element)
	{
			if ((x > 1) && (x < 12) && (y > 1) && (y < 12))
			{
				index = ((x % 2 == 0) && (y % 2 == 0)) ? 0 : (((x % 2 != 0) && (y % 2 != 0))) ? 0 : 1;
				string color = colors[index];
				if ((element == "X")||(element == "#"))
					cout << color << "\033[1;31m" << element << "\033[0m";
				else
				{
					if (element.size() > 2)
					{
						if (element.size() > 3)
						{
							if ((element[1] == '.') && (element[2] == '1') && (data2[9]->Get_Damaged() == true))
								cout << color << "\033[1;31m" << "#" << "\033[0m";
						    else
							    cout << color << " " << "\033[0m";
						}
						else
						{
							if ((element[1] == '.') && (data2[(int(element[2])) - 49]->Get_Damaged() == true))
								cout << color << "\033[1;31m" << "#" << "\033[0m";
						    else
							    cout << color << " " << "\033[0m";
						}
					}
					else
						cout << color << " " << "\033[0m";
				}
			}
			else
				cout << element;
			++x;
			if (x >= 13)
				x = 0;
		});
	cout << std::endl;
	++y;
	});
	cout << "\033[0m";
}

Bot::~Bot()
{
	for (auto& row : sea2)
		row.clear();
	sea2.clear();
}