#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Game.hpp"
#include "Player.hpp"
#include "Bot.hpp"

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
    game.Start(player);
    return 0;
}

/*
		h = 3;
		w = type + 2;
		if ((x - 1) >= 1)
			--x0;
		else
			--w;
		if (((int(y) - 64) - 1) >= 1)
			--y0;
		else
			--h;
		int x2 = x0-1 , y2 = y0-1;
		for (int i = 0; i < h; ++i,++y2)
		{
			for (int j = 0; j < w; ++j,++x2)
			{
				if (player->Get_vec1()[x2][y2] != " ")
					res = true;
				if (player->Get_vec1()[x2 + 1][y2] == "|")
					++x2;
			}
			x2 = x0 - 1;
			if (player->Get_vec1()[x2][y2 + 1] == "-")
				++y2;
		}
		*/

		/*
				h = type + 2;
				w = 3;
				if ((x - 1) >= 1)
					--x0;
				else
					--w;
				if (((int(y) - 64) - 1) >= 1)
					--y0;
				else
					--h;
				int x2 = x0 - 1, y2 = y0 - 1;
				for (int i = 0; i < h; ++i, ++y2)
				{
					for (int j = 0; j < w; ++j, ++x2)
					{
						if (player->Get_vec1()[x2][y2] != " ")
							res = true;
						if (player->Get_vec1()[x2 + 1][y2] == "|")
							++x2;
					}
					x2 = x0 - 1;
					if (player->Get_vec1()[x2][y2 + 1] == "-")
						++y2;
				}*/