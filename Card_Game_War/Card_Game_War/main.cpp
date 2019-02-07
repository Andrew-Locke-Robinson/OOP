#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "War.hpp"

int main()
{
	std::srand(std::time(nullptr));

	int player1_wins = 0, player2_wins = 0;

	War game;

	int who_won = game.PlayWar();
	if (who_won == 1)
	{
		player1_wins += 1;
	}
	else {
		player2_wins += 1;
	}
	
	int x;
	std::cin >> x;
}