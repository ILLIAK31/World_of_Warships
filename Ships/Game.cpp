#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Game.hpp"
#include "Ship.hpp"
#include "Ship_4x.hpp"

int Game::count_ships = 10;
int Game::count_4x = 1;
int Game::count_3x = 2;
int Game::count_2x = 3;
int Game::count_x = 4;

void Game::Start()
{
	cout << "\tGame Ships\n"<<"\tYou will be playing with bot\n\tYou must create 10 ships\n"<<"\tOne ship of size 4 , two ships of size 2 , three ships of size 2 and four ships of size 1\n";
	int menu;
	do 
	{
		cout << "\n\tAdd " << count_4x << " ship of size 4, "<< count_3x <<" ships of size 2, "<< count_2x << " ships of size 2 and " << count_x <<" ships of size 1\n" << "\tGive ship :\n\t1. 4x ship\n\t2. 3x ship\n\t3. 2x ship \n\t4. x ship\n\tEnter : ";
		cin >> menu;
		string color, symbol, rotation ;
		int x;
		char y;
		if (menu == 1)
		{
			cout << "\n\tGive symbol (but without # and _ ) : ";
			cin >> symbol;
			if (Check_val_sym(symbol))
				continue;
			cout << "\n\tGive rotation (V - Verticale or G - Gorizontal) : ";
			cin >> rotation;
			if (Check_val_rot(rotation))
				continue;
			cout << "\n\tEnter color(Red, Blue, Green, Yellow, Purple, White) : ";
			cin >> color;
			if (Check_val_col(color))
				continue;
			cout << "\n\tGive position of ship (A,B,C,D,E,F,G,H,I,J) : ";
			cin >> y;
			cout << "\n\tGive position of ship (1...10) : ";
			cin >> x;
			if (Check_val_xy(x,y,4,rotation))
				continue;
			//
			Ship_4x* obj = new Ship_4x(symbol,rotation,color);
		}
		else if (menu == 2)
		{
			//
		}
		else if (menu == 3)
		{
			//
		}
		else if (menu == 4)
		{
			//
		}
		else
		{
			cout << "\n\tWrong number\n";
			continue;
		}
	} while (count_ships != 0);
}

bool Game::Check_val_sym(const string sym)
{
	if ((sym == "#") || (sym.size() > 1) || (sym == "_"))
	{
		cout << "\n\tWrong symbol\n";
		return true;
	}
	return false;
}

bool Game::Check_val_rot(const string rot)
{
	if ((rot != "V") && (rot != "G"))
	{
		cout << "\n\tWrong rotation\n";
		return true;
	}
	return false;
}

bool Game::Check_val_col(const string col)
{
	if ((col != "Red") && (col != "Blue") && (col != "Green") && (col != "Yellow") && (col != "Purple") && (col != "White"))
	{
		cout << "\n\tWrong color\n";
		return true;
	}
	return false;
}

bool Game::Check_val_xy(const int x, const char y,int type, const string rot)
{
	if ((x < 1) || (x > 10) || ((int(y) - 64) < 1) || ((int(y) - 64) > 10) || ((rot == "G") && ((x + (type - 1))>10)) || ((rot == "V") && (((int(y)-64) + (type - 1)) > 10)))
	{
		cout << "\n\tWrong x or y\n";
		return true;
	}
}

Game::~Game(){}