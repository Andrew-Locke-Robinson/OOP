#include <iostream>
#include <vector>
#include "Deck.hpp"

int main()
{
	Deck main_deck;

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