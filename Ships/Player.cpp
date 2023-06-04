#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

#include "Player.hpp"
#include "Ship.hpp"
#include "Ship_4x.hpp"
#include "Ship_3x.hpp"
#include "Ship_2x.hpp"
#include "Ship_1x.hpp"

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
				if (element.size() == 1)
				{
					if ((element == "X") || (element == "#"))
						cout << color << "\033[1;31m" << element << "\033[0m";
					else 
						cout << color << element << "\033[0m";
				}
				else if (element.size() == 2)
				{
					if ((element[1] != '.') && (element[0] == '.'))
						cout << color << "\033[1;" << data1[(int(element[1])) - 49]->Get_color() << data1[(int(element[1])) - 49]->Get_symbol() << "\033[0m";
				}
				else if (element.size() == 3)
				{
					if (element[1] != '.')
						cout << color << "\033[1;" << data1[9]->Get_color() << data1[9]->Get_symbol() << "\033[0m";
					else if ((element[1] == '.') && (element[2] == '1') && (data1[0]->Get_Damaged() == true))
						cout << color << "\033[1;31m" << "#" << "\033[0m";
					else if ((element[1] == '.') && (data1[(int(element[2])) - 49]->Get_Damaged() == true))
						cout << color << "\033[1;31m" << "#" << "\033[0m";
					else
						cout << color << " " << "\033[0m";
				}
				else if (element.size() == 4)
				{
					if ((element[1] == '.') && (element[2] == '1') && (data1[9]->Get_Damaged() == true))
						cout << color << "\033[1;31m" << "#" << "\033[0m";
					else
						cout << color << " " << "\033[0m";
				}
				else
					cout << color << element <<"\033[0m" ;
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
		int index=0;
		bool res = true;
		if ((bot->Get_vec2()[int(y) - 63][x + 1].size() > 1) && (bot->Get_vec2()[int(y) - 63][x + 1][0] == '.') && (bot->Get_vec2()[int(y) - 63][x + 1][1] != '.'))
		{
			bot->Get_vec2()[int(y) - 63][x + 1] = "X";
			cout << "\n\tBoom\n";
			for (auto& obj : data2)
			{
				for (int i = 0; obj->pos[i] != ""; ++i)
				{
					if ((int(obj->pos[i][0])-48 == int(y) - 65) && (int(obj->pos[i][1])-48 == x - 1))
					{
						int len=0;
						for(int k = 0; obj->pos[k] != ""; ++k, ++len){}
						int w = len+2 , h = 3 , x2 , y2 ,x3;
						if (obj->pos[0].size() > 2)
						{
							x2 = int(obj->pos[0][2]) - 46;
							y2 = int(obj->pos[0][1]) - 46;
						}
						else
						{
							x2 = int(obj->pos[0][1]) - 46;
							y2 = int(obj->pos[0][0]) - 46;
						}
						string s = "X";
						s += obj->pos[i];
						obj->pos[i] = s;
						for (int j = 0; obj->pos[j] != ""; ++j)
						{
							if(obj->pos[j].size()<3)
								res = false;
						}
						if (res == true)
						{
							if (obj->Get_rotation() == "V")
							{
								w = 3;
								h = len + 2;
							}
							if (x2 - 1 >= 0)
								--x2;
							if (y2 - 1 >= 0)
								--y2;
							x3 = x2;
							for (int y0 = 0; y0 < h; ++y0, ++y2)
							{
								for (int x0 = 0; x0 < w; ++x0, ++x2)
								{
									if (bot->Get_vec2()[y2][x2].size() > 2)
										if (bot->Get_vec2()[y2][x2][2] != (index + 1))
										{
											bot->Get_vec2()[y2][x2] = "#";
										}
								}
								x2 = x3;
							}
							obj->Get_Damaged() = true;
							--bot->Get_Count2();
						}
					}
				}
				++index;
			}
			cout << "\n\tYour map\n";
			this->Print(data1);
			cout << "\n\n\tBot map\n";
			bot->Print(data2);
			cout << endl;
			return true;
		}
		else
		{
			bot->Get_vec2()[int(y) - 63][x + 1] = "#";
			return false;
		}
	}
}

bool Player::Check(Bot* bot ,const int x , const int y)
{
	return ((x>10)||(x<1)||(int(y)-64 >10)||(int(y)-64 < 1)||(bot->Get_vec2()[int(y)-63][x+1] == "#")||(bot->Get_vec2()[int(y) - 63][x + 1] == "X")) ? true : false;
}

void Player::Random(Player* player,vector<Ship*>& data1)
{
	count_ships = 10;
	count_4x = 1;
	count_3x = 2;
	count_2x = 3;
	count_x = 4;
	string colors[6] = { "Red", "Blue", "Green", "Yellow","Purple", "White" };
	string rotations[2] = { "V","G" };
	string color, rotation;
	string symbols[4] = { "!","@","$","%" };
	int x, random_number1, random_number2, random_number3;
	char ys[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	char y;
	do
	{
		player->Random_num(x, random_number1, random_number2, random_number3);
		color = colors[random_number2 - 1];
		rotation = rotations[random_number3 - 1];
		y = ys[random_number1 - 1];
		if (Enter_data3(player, symbols[0], rotation, color, x, y, 4))
			continue;
		Ship_4x* ship = new Ship_4x(symbols[0], rotation, color, x, y);
		player->Add(ship, player);
		data1.push_back(ship);
		--count_ships;
		--count_4x;
		ship = nullptr;
		for (int i = 0; i < 2;)
		{
			player->Random_num(x, random_number1, random_number2, random_number3);
			color = colors[random_number2 - 1];
			rotation = rotations[random_number3 - 1];
			y = ys[random_number1 - 1];
			if (Enter_data3(player, symbols[1], rotation, color, x, y, 3))
				continue;
			Ship_3x* ship = new Ship_3x(symbols[1], rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_3x;
			++i;
			ship = nullptr;
		}
		for (int i = 0; i < 3;)
		{
			player->Random_num(x, random_number1, random_number2, random_number3);
			color = colors[random_number2 - 1];
			rotation = rotations[random_number3 - 1];
			y = ys[random_number1 - 1];
			if (Enter_data3(player, symbols[2], rotation, color, x, y, 2))
				continue;
			Ship_2x* ship = new Ship_2x(symbols[2], rotation, color, x, y);
			player->Add(ship,player);
			data1.push_back(ship);
			--count_ships;
			--count_2x;
			++i;
			ship = nullptr;
		}
		for (int i = 0; i < 4;)
		{
			player->Random_num(x, random_number1, random_number2, random_number3);
			color = colors[random_number2 - 1];
			rotation = rotations[random_number3 - 1];
			y = ys[random_number1 - 1];
			if (Enter_data3(player, symbols[3], rotation, color, x, y, 1))
				continue;
			Ship_1x* ship = new Ship_1x(symbols[3], rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_x;
			++i;
			ship = nullptr;
		}
	}while (count_ships != 0);
}

void Player::Random_num(int& num1, int& num2, int& num3, int& num4)
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

bool Player::Enter_data3(Player* player, string& symbol, string& rotation, string& color, int& x, char& y, int type)
{
	if ((symbol == "#") || (symbol.size() > 1) || (symbol == "_") || (symbol == "X") ? true : false)
		return true;
	if (player->Check_val_xy3(x, y, type, rotation, player))
		return true;
	return false;
}

bool Player::Check_val_xy3(const int x, const char y, int type, const string rot, Player* player)
{
	bool res = false;
	int x0 = x, y0 = int(y) - 64, h, w;
	if (rot == "G")
	{
		if ((x < 1) || ((int(y) - 64) < 1) || (x > 10) || ((int(y) - 64) > 10) || (((x + type) - 1) > 10))
			return true;
		w = type;
		int x2 = x0 + 1, y2 = y0 + 1;
		for (int i = 0; i < w; ++i, ++x2)
			if (player->Get_vec1()[y2][x2] != " ")
				res = true;
	}
	else
	{
		if ((x < 1) || ((int(y) - 64) < 1) || (x > 10) || ((int(y) - 64) > 10) || (((int(y) - 65) + type) > 10))
			return true;
		h = type;
		int x2 = x0 + 1, y2 = y0 + 1;
		for (int i = 0; i < h; ++i, ++y2)
			if (player->Get_vec1()[y2][x2] != " ")
				res = true;
	}
	if (res)
		return true;
	return false;
}

Player::~Player()
{
	for (auto& row : sea1)
		row.clear();
	sea1.clear();
}