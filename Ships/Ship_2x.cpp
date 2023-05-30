#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship_2x.hpp"

Ship_2x::Ship_2x(const string symbol, const string rotation, const string color, const int x, const char y) :Ship(symbol, rotation, color, x, y) {}

void Ship_2x::Add_Ship(Ship* ship, Player* player)
{
	++player->Get_Count();
	int x0 = ship->Get_x(), y0 = int(ship->Get_y()) - 64, h, w, count = 0;
	if (ship->Get_rotation() == "G")
	{
		h = 3;
		w = 4;
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
				if ((i == 0) && (h == 3) && ((w == 4) || (w == 3)))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else if ((i == 1) && (h == 3) && (w == 4))
				{
					if ((j == 0) || (j == 3))
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
					else
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 1) && (h == 3) && (w == 3))
				{
					if (j == 2)
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
					else
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 2) && (h == 3) && ((w == 4) || (w == 3)))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else if ((i == 0) && (h == 2) && (w == 3))
				{
					if (j == 2)
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
					else
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 0) && (h == 2) && (w == 4))
				{
					if ((j == 0) || (j == 3))
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
					else
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 1) && (h == 2) && ((w == 3) || (w == 4)))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				if (player->Get_vec1()[y2][x2 + 1] == "|")
					++j;
			}
			x2 = x0 + 1;
			if (player->Get_vec1()[y2 + 1][x2] == "-")
				++i;
		}
	}
	else
	{
		h = 4;
		w = 3;
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
				if ((i == 0) && ((w == 3)||(w == 2)) && (h == 4))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else if ((i == 0) && (w == 2) && (h == 3))
				{
					if (j == 0)
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
					else
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				}
				else if ((i == 0) && (w == 3) && (h == 3))
				{
					if (j == 1)
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
					else
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				}
				else if ((h == 3) && (i != 2) && (w == 2))
				{
					if (j == 0)
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
					else
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count()); ;
				}
				else if ((h == 3) && (i != 2) && (w == 3))
				{
					if (j == 1)
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
					else
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				}
				else if ((h == 4) && ((i != 3) && (i != 0)) && (w == 2))
				{
					if (j == 1)
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
					else
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((h == 4) && ((i != 3) && (i != 0)) && (w == 3))
				{
					if ((j == 2) || (j == 0))
						player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
					else
					{
						player->Get_vec1()[y2][x2] = "." + to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 2) && (h == 3))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				else if ((i == 3) && (h == 4))
					player->Get_vec1()[y2][x2] = ".." + to_string(player->Get_Count());
				if (player->Get_vec1()[y2][x2 + 1] == "|")
					++j;
			}
			x2 = x0 + 1;
			if (player->Get_vec1()[y2 + 1][x2] == "-")
				++i;
		}
	}
}

void Ship_2x::Add_Ship_Bot(Ship* ship, Bot* bot)
{
	//
}

Ship_2x::~Ship_2x() {}