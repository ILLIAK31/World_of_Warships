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

bool Bot::Bot_Go(Player* player, vector<Ship*>& data1, vector<Ship*>& data2)
{
	int x , y0;
	char y;
	char ys[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	this->Random_xy(x,y0);
	y = ys[y0 - 1];
	if (this->Check(player, x, y))
	{
		cout << "\n\tWrong\n";
		return true;
	}
	else
	{
		int index = 0;
		bool res = true;
		if ((player->Get_vec1()[int(y) - 63][x + 1].size() > 1) && (player->Get_vec1()[int(y) - 63][x + 1][0] == '.') && (player->Get_vec1()[int(y) - 63][x + 1][1] != '.'))
		{
			player->Get_vec1()[int(y) - 63][x + 1] = "X";
			for (auto& obj : data2)
			{
				for (int i = 0; obj->pos[i] != ""; ++i)
				{
					if ((int(obj->pos[i][0]) - 48 == int(y) - 65) && (int(obj->pos[i][1]) - 48 == x - 1))
					{
						int len = 0;
						for (int k = 0; obj->pos[k] != ""; ++k, ++len) {}
						int w = len + 2, h = 3, x2, y2, x3;
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
							if (obj->pos[j].size() < 3)
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
									if (player->Get_vec1()[y2][x2].size() > 2)
										if (player->Get_vec1()[y2][x2][2] != (index + 1))
										{
											player->Get_vec1()[y2][x2] = "#";
										}
								}
								x2 = x3;
							}
							obj->Get_Damaged() = true;
							--player->Get_Count();
						}
						cout << "\n\tYour map\n";
						player->Print(data1);
						cout << "\n\n\tBot map\n";
						this->Print(data2);
						cout << endl;
						break;
					}
				}
				++index;
			}
			return true;
		}
		else
		{
			player->Get_vec1()[int(y) - 63][x + 1] = "#";
			return false;
		}
	}
	cout << "\n\tYour map\n";
	player->Print(data1);
	cout << "\n\n\tBot map\n";
	this->Print(data2);
	cout << endl;
}

void Bot::Random_xy(int& num1, int& num2)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(1, 10);
	num1 = distribution(generator);
	num2 = distribution(generator);
}

bool Bot::Check(Player* player, const int x, const int y)
{
	return ((x > 10) || (x < 1) || (int(y) - 64 > 10) || (int(y) - 64 < 1) || (player->Get_vec1()[int(y) - 63][x + 1] == "#") || (player->Get_vec1()[int(y) - 63][x + 1] == "X")) ? true : false;
}

Bot::~Bot()
{
	for (auto& row : sea2)
		row.clear();
	sea2.clear();
}