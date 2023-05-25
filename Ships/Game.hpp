#pragma once

class Game
{
private:
	static int count_ships , count_4x , count_3x , count_2x , count_x;
public:
	Game()=default;
	void Start();
	virtual ~Game();
};