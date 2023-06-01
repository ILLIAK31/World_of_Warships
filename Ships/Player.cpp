#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

vector<vector<string>>& Player::Get_vec1()
{
	return this->sea1;
}

void Player::Add(Ship* ship,Player* player)
{
	ship->Add_Ship(ship,player);
}

int& Player::Get_Count()
{
	return this->count_player_ship;
}

void Player::Print(vector<Ship*> data1)
{
	int x = 0, y = 0 , index;
	string colors[2] = { "\033[46m","\033[100m" };
	cout << endl;
	for_each(this->Get_vec1().begin(), this->Get_vec1().end(),[data1, &x, &y, &index, &colors](const vector<string>& row){for_each(row.begin(), row.end(), [data1, &x, &y, &index, &colors](const string& element)
	{
			if ((x > 1) && (x < 12) && (y > 1) && (y < 12))
			{
				index = ((x % 2 == 0) && (y%2 == 0)) ? 0 : (((x % 2 != 0) && (y % 2 != 0)))?0:1;
				string color = colors[index];
				if (element.size() > 1)
				{
					if ((element[1] == '.') && (element.size() > 2))
					{
						if (data1[(int(element[2])) - 49]->Get_Damaged() == true)
							cout << color << "\033[1;31m"<<"#" << "\033[0m";
						else
							cout << color << " " << "\033[0m";
					}
					else if ((element[1] != '.') && (element[0] == '.'))
						cout << color << "\033[1;" << data1[(int(element[1])) - 49]->Get_color() << data1[(int(element[1])) - 49]->Get_symbol() << "\033[0m";
					else
						cout << color << element << "\033[0m";
				}
				else
				{
					if((element == "X")||(element == "#"))
						cout << color << "\033[1;31m" << element << "\033[0m";
					else
						cout << color << element << "\033[0m";
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

bool Player::Player_Go(Bot* bot,vector<Ship*>& data1, vector<Ship*>& data2)
{
	int x;
	char y;
	cout << "\n\tYour turn\n\tEnter x : ";
	cin >> x;
	cout << "\tEnter y : ";
	cin >> y;
	if (Check(bot,x, y))
	{
		cout << "\n\tWrong\n";
		return true;
	}
	else
	{
		bool res = true;
		if ((bot->Get_vec2()[int(y) - 63][x + 1].size() > 1) && (bot->Get_vec2()[int(y) - 63][x + 1][0] == '.') && (bot->Get_vec2()[int(y) - 63][x + 1][1] != '.'))
		{
			bot->Get_vec2()[int(y) - 63][x + 1] = "X";
			for (auto& obj : data2)
			{
				for (int i = 0; obj->pos[i] != ""; ++i)
				{
					if ((int(obj->pos[i][0]) == int(y) - 65) && (int(obj->pos[i][1]) == x - 1))
					{
						obj->pos[i] = "X";
						break;
						for (int j = 0; obj->pos[j] != ""; ++j)
						{
							if (obj->pos[j] != "X")
								res = false;
						}
						if (res == true)
						{
							obj->Get_Damaged() = true;
							--bot->Get_Count2();
						}
						break;
					}
				}
			}
			return true;
		}
		else
		{
			bot->Get_vec2()[int(y) - 63][x + 1] = "#";
			return false;
		}
	}
	cout << "\n\tYour map\n";
	this->Print(data1);
	cout << "\n\n\tBot map\n";
	bot->Print(data2);
	cout << endl;
}

bool Player::Check(Bot* bot ,const int x , const int y)
{
	return ((x>10)||(x<1)||(int(y)-64 >10)||(int(y)-64 < 1)||(bot->Get_vec2()[int(y)-64][x+1] == "#")||(bot->Get_vec2()[int(y) - 64][x + 1] == "X")) ? true : false;
}

Player::~Player()
{
	for (auto& row : sea1)
		row.clear();
	sea1.clear();
}