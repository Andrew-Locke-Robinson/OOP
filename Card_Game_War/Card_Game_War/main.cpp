#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "War.hpp"

int main()
{
	std::srand(std::time(nullptr));

	War game;

	game.InitializePlayerDecks();
	game.PlayWar();

	int x;
	std::cin >> x;
}