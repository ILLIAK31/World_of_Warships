#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship_1x.hpp"

Ship_1x::Ship_1x(const string symbol, const string rotation, const string color, const int x, const char y) :Ship(symbol, rotation, color, x, y) {}

void Ship_1x::Add_Ship(Ship* ship, Player* player)
{
	++player->Get_Count();
	int x0 = ship->Get_x(), y0 = int(ship->Get_y()) - 64, h, w, count = 0;
	h = w = 3;
	if ((ship->Get_x() - 1) >= 1)
		--x0;
	else
		--w;
	if ((y0 - 1) >= 1)
		--y0;
	else
		--h;
	int x2 = x0 + 1, y2 = y0 + 1;
	for (int i = 0; i < h; ++i, ++y2)
	{
		for (int j = 0; j < w; ++j, ++x2)
		{
			if ((i == 0) && (h == 3) && ((w == 2) || (w == 3)))
				player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
			else if ((i == 1) && (h == 3) && (w == 3))
			{
				if ((j == 0) || (j == 2))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else
				{
					player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 1) && (h == 3) && (w == 2))
			{
				if (j == 1)
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else
				{
					player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 2) && (h == 3) && ((w == 3) || (w == 2)))
				player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
			else if ((i == 0) && (h == 2) && (w == 2))
			{
				if (j == 1)
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else
				{
					player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 0) && (h == 2) && (w == 3))
			{
				if ((j == 0) || (j == 2))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else
				{
					player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
				}
			else if ((i == 1) && (h == 2) && ((w == 3) || (w == 2)))
				player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
			if (player->Get_vec1()[y2][x2 + 1] == "|")
				++j;
		}
		x2 = x0 + 1;
		if (player->Get_vec1()[y2 + 1][x2] == "-")
			++i;
	}
}

void Ship_1x::Add_Ship_Bot(Ship* ship, Bot* bot)
{
	++bot->Get_Count2();
	int x0 = ship->Get_x(), y0 = int(ship->Get_y()) - 64, h, w, count = 0;
	h = w = 3;
	if ((ship->Get_x() - 1) >= 1)
		--x0;
	else
		--w;
	if ((y0 - 1) >= 1)
		--y0;
	else
		--h;
	int x2 = x0 + 1, y2 = y0 + 1;
	for (int i = 0; i < h; ++i, ++y2)
	{
		for (int j = 0; j < w; ++j, ++x2)
		{
			if ((i == 0) && (h == 3) && ((w == 2) || (w == 3)))
				bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
			else if ((i == 1) && (h == 3) && (w == 3))
			{
				if ((j == 0) || (j == 2))
					bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
				else
				{
					bot->Get_vec2()[y2][x2] = "." + to_string(bot->Get_Count2());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 1) && (h == 3) && (w == 2))
			{
				if (j == 1)
					bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
				else
				{
					bot->Get_vec2()[y2][x2] = "." + to_string(bot->Get_Count2());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 2) && (h == 3) && ((w == 3) || (w == 2)))
				bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
			else if ((i == 0) && (h == 2) && (w == 2))
			{
				if (j == 1)
					bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
				else
				{
					bot->Get_vec2()[y2][x2] = "." + to_string(bot->Get_Count2());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 0) && (h == 2) && (w == 3))
			{
				if ((j == 0) || (j == 2))
					bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
				else
				{
					bot->Get_vec2()[y2][x2] = "." + to_string(bot->Get_Count2());
					pos[0] = (to_string(y2 - 2) + to_string(x2 - 2));
				}
			}
			else if ((i == 1) && (h == 2) && ((w == 3) || (w == 2)))
				bot->Get_vec2()[y2][x2] = ".." + to_string(bot->Get_Count2());
			if (bot->Get_vec2()[y2][x2 + 1] == "|")
				++j;
		}
		x2 = x0 + 1;
		if (bot->Get_vec2()[y2 + 1][x2] == "-")
			++i;
	}
}

Ship_1x::~Ship_1x() {}