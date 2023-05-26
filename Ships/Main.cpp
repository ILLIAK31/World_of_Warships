#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Game.hpp"
#include "Player.hpp"
#include "Bot.hpp"

int main()
{
    Game game;
    Player* player = new Player();
    game.Start();
    return 0;
}