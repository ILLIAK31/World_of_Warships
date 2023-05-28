#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Game.hpp"
#include "Player.hpp"
#include "Bot.hpp"
#include "Ship.hpp"

int Game::count_ships = 10;
int Game::count_4x = 1;
int Game::count_3x = 2;
int Game::count_2x = 3;
int Game::count_x = 4;
int Player::count_player_ship = 0;

int main()
{
    Game game;
    Player* player = new Player();
    vector<Ship*> data1;
    game.Start(player,data1);
    return 0;
}



			/*
			cout << data1[0]->Get_color() << data1[0]->Get_symbol();
			for (const auto row : player->Get_vec1()) {
				for (const auto element : row)
				{
					if (element == " ")
						cout << " ";
					else if (element == ".1")
						cout << "\033[1;" << data1[(int(element[1])) - 49]->Get_color() << data1[(int(element[1])) - 49]->Get_symbol() << "\033[0m";
					else if (element[1] == '.')
						cout << "_";
					else
						cout << element;

				}
				cout << endl;
			}
			}*/