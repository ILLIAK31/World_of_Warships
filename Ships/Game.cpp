#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Game.hpp"
#include "Player.hpp"
#include "Ship_4x.hpp"
#include "Ship_3x.hpp"
#include "Ship_2x.hpp"

void Game::Start(Player* player,vector<Ship*>& data1)
{
	cout << "\n\tGame Ships\n"<<"\tYou will be playing with bot\n\tYou must create 10 ships\n"<<"\tOne ship of size 4 , two ships of size 3 , three ships of size 2 and four ships of size 1\n\t!!! Ships must be at least one square away from each other !!!\n\n\n";
	int menu;
	do 
	{
		cout << endl;
		for (const auto row : player->Get_vec1()) {
			for (const auto element : row)
				cout << element;
			cout << endl;
		}
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
			cout << "\n\tGive 1-character symbol (but without # , X and _ ) : ";
			cin >> symbol;
			if (player->Check_val_sym(symbol))
				continue;
			cout << "\n\tGive rotation (V - Verticale or G - Gorizontal) : ";
			cin >> rotation;
			if (player->Check_val_rot(rotation))
				continue;
			cout << "\n\tEnter color(Red, Blue, Green, Yellow, Purple, White) : ";
			cin >> color;
			if (player->Check_val_col(color))
				continue;
			cout << "\n\tGive position of ship (A,B,C,D,E,F,G,H,I,J) : ";
			cin >> y;
			cout << "\n\tGive position of ship (1...10) : ";
			cin >> x;
			if (player->Check_val_xy(x,y,4,rotation,player))
				continue;
			Ship_4x* ship = new Ship_4x(symbol,rotation,color,x,y);
			player->Add(ship,player);
			data1.push_back(ship);
			--count_ships;
			--count_4x;
		}
		else if ((menu == 2) && (count_3x != 0))
		{
			cout << "\n\tGive 1-character symbol (but without # , X and _ ) : ";
			cin >> symbol;
			if (player->Check_val_sym(symbol))
				continue;
			cout << "\n\tGive rotation (V - Verticale or G - Gorizontal) : ";
			cin >> rotation;
			if (player->Check_val_rot(rotation))
				continue;
			cout << "\n\tEnter color(Red, Blue, Green, Yellow, Purple, White) : ";
			cin >> color;
			if (player->Check_val_col(color))
				continue;
			cout << "\n\tGive position of ship (A,B,C,D,E,F,G,H,I,J) : ";
			cin >> y;
			cout << "\n\tGive position of ship (1...10) : ";
			cin >> x;
			if (player->Check_val_xy(x, y, 3, rotation, player))
				continue;
			Ship_3x* ship = new Ship_3x(symbol, rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_3x;
		}
		else if ((menu == 3) && (count_2x != 0))
		{
			cout << "\n\tGive 1-character symbol (but without # , X and _ ) : ";
			cin >> symbol;
			if (player->Check_val_sym(symbol))
				continue;
			cout << "\n\tGive rotation (V - Verticale or G - Gorizontal) : ";
			cin >> rotation;
			if (player->Check_val_rot(rotation))
				continue;
			cout << "\n\tEnter color(Red, Blue, Green, Yellow, Purple, White) : ";
			cin >> color;
			if (player->Check_val_col(color))
				continue;
			cout << "\n\tGive position of ship (A,B,C,D,E,F,G,H,I,J) : ";
			cin >> y;
			cout << "\n\tGive position of ship (1...10) : ";
			cin >> x;
			if (player->Check_val_xy(x, y, 2, rotation, player))
				continue;
			Ship_2x* ship = new Ship_2x(symbol, rotation, color, x, y);
			player->Add(ship, player);
			data1.push_back(ship);
			--count_ships;
			--count_2x;
		}
		else if ((menu == 4) && (count_x != 0))
		{
			//
		}
		else
		{
			cout << "\n\tWrong number\n\n";
			continue;
		}
	} while (count_ships != 0);
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
		w = type;
		int x2 = x0 + 1, y2 = y0 + 1;
		for (int i = 0; i < w; ++i,++x2)
			if (player->Get_vec1()[y2][x2] != " ")
				res = true;
	}
	else
	{
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

Game::~Game(){}