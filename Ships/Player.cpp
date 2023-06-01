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
						cout << color << " " << "\033[0m";;
					}
					else if ((element[1] != '.') && (element[0] == '.'))
						cout << color << "\033[1;" << data1[(int(element[1])) - 49]->Get_color() << data1[(int(element[1])) - 49]->Get_symbol() << "\033[0m";
					else
						cout << color << element << "\033[0m";
				}
				else
					cout << color << element << "\033[0m";
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
	std::cout << "\033[0m";
}

bool Player::Player_Go(vector<Ship*>& data1, vector<Ship*>& data2)
{
	int x;
	char y;
	cout << "\n\tYour turn\n\tEnter x : ";
	cin >> x;
	cout << "\tEnter y : ";
	cin >> y;
	//
	return false;
}

Player::~Player()
{
	for (auto& row : sea1)
		row.clear();
	sea1.clear();
}