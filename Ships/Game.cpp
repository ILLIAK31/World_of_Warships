#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Game.hpp"

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
		if (menu == 1)
		{

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
		--Game::count_ships;
	} while (count_ships != 0);
}

Game::~Game(){}