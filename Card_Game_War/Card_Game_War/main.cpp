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
	for (int i = 0; i < 1000; ++i)
	{
		int who_won = game.PlayWar();
		if (who_won == 1)
		{
			player1_wins += 1;
		}
		else {
			player2_wins += 1;
		}
	}
	std::cout << static_cast<float>(player1_wins) / static_cast<float>(player2_wins) << std::endl;
	int x;
	std::cin >> x;
}