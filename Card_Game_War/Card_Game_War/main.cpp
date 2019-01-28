#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "War.hpp"

int main()
{
	std::srand(std::time(nullptr));

	War game;

	for (int s = 0; s < 4; ++s)
	{
		for (int r = 0; r < 13; r++)
		{
			Card new_card(static_cast<Card::Suit>(s), static_cast<Card::Rank> (r));
			main_deck.AddCard(new_card);
		}
	}

	int x;
	std::cin >> x;
}