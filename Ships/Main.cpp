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
int Bot::count_player_ship2 = 0;

void Delete_All(Player* player,Bot* bot, vector<Ship*>& data1, vector<Ship*>& data2);

int main()
{
    Game game;
    Player* player = new Player();
	Bot* bot = new Bot();
    vector<Ship*> data1 , data2;
    game.Start(player,data1);
	game.Start_Bot(bot, data2);
	game.Battle(player, bot, data1, data2);
	Delete_All(player, bot,data1,data2);
    return 0;
}

void Delete_All(Player* player, Bot* bot, vector<Ship*>& data1, vector<Ship*>& data2)
{
	delete player;
	delete bot;
	for (auto& obj : data1)
	{
		delete obj;
		obj = nullptr;
	}
	for (auto& obj : data2)
	{
		delete obj;
		obj = nullptr;
	}
}