#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Ship_4x.hpp"

Ship_4x::Ship_4x(const string color, const string rotation, const string symbol,const int x , const char y):Ship(color,rotation,symbol,x,y){}

void Ship_4x::Add_Ship(Ship* ship,Player* player)
{
	++player->Get_Count();
	int x0 = ship->Get_x(), y0 = int(ship->Get_y()) - 64 , h, w , count = 0;
	if (ship->Get_rotation() == "G")
	{
		h = 3;
		w = 6;
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
				if ((i == 0)&&(h == 3)&&((w == 6)||(w == 5)))
					player->Get_vec1()[y2][x2] = "_";
				else if ((i == 1) && (h == 3) && (w == 6))
				{
					if((j == 0)||(j == 5))
						player->Get_vec1()[y2][x2] = "_";
					else
					{
						player->Get_vec1()[y2][x2] = to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 1) && (h == 3) && (w == 5))
				{
					if (j == 4)
						player->Get_vec1()[y2][x2] = "_";
					else
					{
						player->Get_vec1()[y2][x2] = to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 2) && (h == 3) && ((w == 6) || (w == 5)))
					player->Get_vec1()[y2][x2] = "_";
				else if ((i == 0) && (h == 2) && (w == 5))
				{
					if (j == 4)
						player->Get_vec1()[y2][x2] = "_";
					else
					{
						player->Get_vec1()[y2][x2] = to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 0) && (h == 2) && (w == 6))
				{
					if ((j == 0) || (j == 5))
						player->Get_vec1()[y2][x2] = "_";
					else
					{
						player->Get_vec1()[y2][x2] = to_string(player->Get_Count());
						pos[count++] = (to_string(y2 - 2) + to_string(x2 - 2));
					}
				}
				else if ((i == 1) && (h == 2) && ((w == 5) || (w == 6)))
					player->Get_vec1()[y2][x2] = "_";
				if (player->Get_vec1()[y2][x2+1] == "|")
					++x2;
			}
			x2 = x0 + 1;
			if (player->Get_vec1()[y2+1][x2] == "-")
				++y2;
		}
	}
	else
	{
		//
	}
}

Ship_4x::~Ship_4x(){}