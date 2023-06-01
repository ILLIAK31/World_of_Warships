#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

#include "Game.hpp"
#include "Player.hpp"
#include "Bot.hpp"
#include "Ship_4x.hpp"
#include "Ship_3x.hpp"
#include "Ship_2x.hpp"
#include "Ship_1x.hpp"

void Game::Start(Player* player,vector<Ship*>& data1)
{
	cout << "\n\tGame Ships\n"<<"\tYou will be playing with bot\n\tYou must create 10 ships\n"<<"\tOne ship of size 4 , two ships of size 3 , three ships of size 2 and four ships of size 1\n\t!!! Ships must be at least one square away from each other !!!\n\n\n";
	int menu;
	do 
	{
		player->Print(data1);
		cout << "\n\n\tAdd ";
		if (count_4x != 0)
			cout << "\033[1;32m" << count_4x << "\033[0m";
		else
			cout << "\033[1;31m" << count_4x <<"\033[0m";
		cout << " ship of size 4, "; 
		if (count_3x != 0)
			cout << "\033[1;32m" << count_3x << "\033[0m";
		else
			cout << "\033[1;31m" << count_3x << "\033[0m";
		cout << " ships of size 3, "; 
		if (count_2x != 0)
			cout << "\033[1;32m" << count_2x << "\033[0m";
		else
			cout << "\033[1;31m" << count_2x << "\033[0m";
		cout << " ships of size 2 and ";
		if (count_x != 0)
			cout << "\033[1;32m" << count_x << "\033[0m";
		else
			cout << "\033[1;31m" << count_x << "\033[0m";
		cout << " ships of size 1\n" << "\tGive ship :\n\t1. 4x ship\n\t2. 3x ship\n\t3. 2x ship \n\t4. x ship\n\tEnter : ";
		cin >> menu;
		string color, symbol, rotation ;
		int x;
		char y;
		if ((menu == 1)&&(count_4x != 0))
		{
			if (Enter_data(player,symbol,rotation,color,x,y,4))
				continue;
			Ship_4x* ship = new Ship_4x(symbol,rotation,color,x,y);
			player->Add(ship,player);
			data1.push_back(ship);
			--count_ships;
			--count_4x;
			ship = nullptr;
		}
		else if ((menu == 2) && (count_3x != 0))
		{
			if (Enter_data(player, symbol, rotation, color, x, y, 3))
				continue;
			Ship_3x* ship = new Ship_3x(symbol, rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_3x;
			ship = nullptr;
		}
		else if ((menu == 3) && (count_2x != 0))
		{
			if (Enter_data(player, symbol, rotation, color, x, y, 2))
				continue;
			Ship_2x* ship = new Ship_2x(symbol, rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_2x;
			ship = nullptr;
		}
		else if ((menu == 4) && (count_x != 0))
		{
			if (Enter_data(player, symbol, rotation, color, x, y, 1))
				continue;
			Ship_1x* ship = new Ship_1x(symbol, rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_x;
			ship = nullptr;
		}
		else
		{
			cout << "\n\tWrong number\n\n";
			continue;
		}
	} while (count_ships != 0);
	cout << endl;
	player->Print(data1);
	cout << endl;
}


void Game::Start_Bot(Bot* bot, vector<Ship*>& data2)
{
	count_ships = 10;
	count_4x = 1;
	count_3x = 2;
	count_2x = 3;
	count_x = 4;
	string colors[6] = { "Red", "Blue", "Green", "Yellow","Purple", "White" };
	string rotations[2] = { "V","G" };
	string color , rotation;
	string symbols[4] = {"!","@","$","%"};
	int x , random_number1 , random_number2 , random_number3;
	char ys[10] = { 'A','B','C','D','E','F','G','H','I','J'};
	char y;
	cout << "\tBot is creating his sea (please wait few seconds....)" << endl;
	this_thread::sleep_for(chrono::seconds(3));
	do
	{
		bot->Random(x, random_number1, random_number2, random_number3);
		color = colors[random_number2 - 1];
		rotation = rotations[random_number3 - 1];
		y = ys[random_number1 - 1];
		if(Enter_data2(bot,symbols[0], rotation, color, x, y, 4))
			continue;
		Ship_4x* ship = new Ship_4x(symbols[0], rotation, color, x, y);
		bot->Add_Bot(ship, bot);
		data2.push_back(ship);
		--count_ships;
		--count_4x;
		ship = nullptr;
		for (int i = 0; i < 2;)
		{
			bot->Random(x, random_number1, random_number2, random_number3);
			color = colors[random_number2 - 1];
			rotation = rotations[random_number3 - 1];
			y = ys[random_number1 - 1];
			if (Enter_data2(bot, symbols[1], rotation, color, x, y, 3))
				continue;
			Ship_3x* ship = new Ship_3x(symbols[1], rotation, color, x, y);
			bot->Add_Bot(ship, bot);
			data2.push_back(ship);
			--count_ships;
			--count_3x; 
			++i;
			ship = nullptr;
		}
		for (int i = 0; i < 3;)
		{
			bot->Random(x, random_number1, random_number2, random_number3);
			color = colors[random_number2 - 1];
			rotation = rotations[random_number3 - 1];
			y = ys[random_number1 - 1];
			if (Enter_data2(bot, symbols[2], rotation, color, x, y, 2))
				continue;
			Ship_2x* ship = new Ship_2x(symbols[2], rotation, color, x, y);
			bot->Add_Bot(ship, bot);
			data2.push_back(ship);
			--count_ships;
			--count_2x;
			++i;
			ship = nullptr;
		}
		for (int i = 0; i < 4;)
		{
			bot->Random(x, random_number1, random_number2, random_number3);
			color = colors[random_number2 - 1];
			rotation = rotations[random_number3 - 1];
			y = ys[random_number1 - 1];
			if (Enter_data2(bot, symbols[3], rotation, color, x, y, 1))
				continue;
			Ship_1x* ship = new Ship_1x(symbols[3],rotation,color,x,y);
			bot->Add_Bot(ship, bot);
			data2.push_back(ship);
			--count_ships;
			--count_x;
			++i;
			ship = nullptr;
		}
	} while (count_ships != 0);
	cout << endl << "\tBot created his sea" << endl << endl;
	//
	for (vector<string> obj : bot->Get_vec2())
	{
		for (string x : obj)
		{
			if (x.size() > 1)
			{
				if ((x[1] == '.') && (x.size() > 2))
				{
					cout << " ";
				}
				else if ((x[1] != '.') && (x[0] == '.'))
					cout << "\033[1;" << data2[(int(x[1])) - 49]->Get_color() << data2[(int(x[1])) - 49]->Get_symbol() << "\033[0m";
				else
					cout << x;
			}
			else
				cout << x;
		}
		cout << endl;
	}
	//
}

void Game::Battle(Player* player, Bot* bot, vector<Ship*>& data1, vector<Ship*>& data2)
{
	player->Get_Count() = 10;
	bot->Get_Count2() = 10;
	cout << "\n\tGame will start in" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\t3\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\t2\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\t1\n";
	this_thread::sleep_for(chrono::seconds(1));
	do
	{
		while (true)
		{
			if (player->Player_Go(bot,data1,data2))
				continue;
			else
			{
				cout << "\n\tYour map\n";
				player->Print(data1);
				cout << "\n\n\tBot map\n";
				bot->Print(data2);
				cout << endl;
				cout << "\n\tWrong\n";
			}
			break;
		}
		//
	} while ((player->Get_Count() != 0)||(bot->Get_Count2() != 0));
}

bool Game::Check_val_sym(const string sym)
{
	if ((sym == "#") || (sym.size() > 1) || (sym == "_") || (sym == "X"))
	{
		cout << "\n\tWrong symbol\n\n";
		return true;
	}
	return false;
}

bool Game::Check_val_sym2(const string sym)
{
	if ((sym == "#") || (sym.size() > 1) || (sym == "_") || (sym == "X"))
		return true;
	return false;
}

bool Game::Check_val_rot(const string rot)
{
	if ((rot != "V") && (rot != "G"))
	{
		cout << "\n\tWrong rotation\n\n";
		return true;
	}
	return false;
}

bool Game::Check_val_col(const string col)
{
	if ((col != "Red") && (col != "Blue") && (col != "Green") && (col != "Yellow") && (col != "Purple") && (col != "White"))
	{
		cout << "\n\tWrong color\n\n";
		return true;
	}
	return false;
}

bool Game::Check_val_xy(const int x, const char y,int type, const string rot,Player* player)
{
	if (((y != 'A') && (y != 'B') && (y != 'C') && (y != 'D') && (y != 'E') && (y != 'F') && (y != 'G') && (y != 'H') && (y != 'I') && (y != 'J')) || (x < 1) || (x > 10) || ((int(y) - 64) < 1) || ((int(y) - 64) > 10) || ((rot == "G") && ((x + (type - 1))>10)) || ((rot == "V") && (((int(y)-64) + (type - 1)) > 10)))
	{
		cout << "\n\tWrong x or y\n\n";
		return true;
	}
	bool res = false;
	int x0 = x, y0 = int(y)-64 , h , w;
	if(rot == "G")
	{
		if ((x < 1) || ((int(y) - 64) < 1) || (x > 10) || ((int(y) - 64) > 10) || (((x + type)-1) > 10))
		{
			cout << "\n\tWrong x or y\n\n";
			return true;
		}
		w = type;
		int x2 = x0 + 1, y2 = y0 + 1;
		for (int i = 0; i < w; ++i,++x2)
			if (player->Get_vec1()[y2][x2] != " ")
				res = true;
	}
	else
	{
		if ((x < 1) || ((int(y) - 64) < 1) || (x > 10) || ((int(y) - 64) > 10) || (((int(y)-65) + type) > 10))
		{
			cout << "\n\tWrong x or y\n\n";
			return true;
		}
		h = type;
		int x2 = x0 + 1, y2 = y0 + 1;
		for (int i = 0; i < h; ++i, ++y2)
			if (player->Get_vec1()[y2][x2] != " ")
				res = true;
	}
	if (res)
	{
		cout << "\n\tWrong x or y\n\n";
		return true;
	}
	return false;
}

bool Game::Check_val_xy2(const int x, const char y, int type, const string rot, Bot* bot)
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
			if (bot->Get_vec2()[y2][x2] != " ")
				res = true;
	}
	else
	{
		if ((x < 1) || ((int(y) - 64) < 1) || (x > 10) || ((int(y) - 64) > 10) || (((int(y) - 65) + type) > 10))
			return true;
		h = type;
		int x2 = x0 + 1, y2 = y0 + 1;
		for (int i = 0; i < h; ++i, ++y2)
			if (bot->Get_vec2()[y2][x2] != " ")
				res = true;
	}
	if (res)
		return true;
	return false;
}

bool Game::Enter_data(Player* player,string& symbol, string& rotation, string& color, int& x, char& y,int type)
{
	cout << "\n\tGive 1-character symbol (but without # , X and _ ) : ";
	cin >> symbol;
	if (player->Check_val_sym(symbol))
		return true;
	if (type == 1)
		rotation = "V";
	else
	{
		cout << "\n\tGive rotation (V - Verticale or G - Gorizontal) : ";
		cin >> rotation;
	}
	if (player->Check_val_rot(rotation))
		return true;
	cout << "\n\tEnter color(Red, Blue, Green, Yellow, Purple, White) : ";
	cin >> color;
	if (player->Check_val_col(color))
		return true;
	cout << "\n\tGive position of ship (A,B,C,D,E,F,G,H,I,J) : ";
	cin >> y;
	cout << "\n\tGive position of ship (1...10) : ";
	cin >> x;
	if (player->Check_val_xy(x, y,type, rotation, player))
		return true;
	return false;
}

bool Game::Enter_data2(Bot* bot, string& symbol, string& rotation, string& color, int& x, char& y, int type)
{
	if (bot->Check_val_sym2(symbol))
		return true;
	if (bot->Check_val_xy2(x, y, type, rotation,bot))
		return true;
	return false;
}

Game::~Game(){}