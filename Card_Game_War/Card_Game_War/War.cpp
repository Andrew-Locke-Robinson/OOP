#include "War.hpp"
#include <random>
#include <iostream>



War::War()
{
}


War::~War()
{
}

int War::PlayWar()
{
	return 0;
}

void War::InitializePlayerDecks()
{
	int random_list [52];

	// initialize list with nums 0-51
	for(int i = 0; i < 52; ++i)
	{
		random_list[i] = i;
	}
	for (int i = 0; i < 52; ++i)
	{
		RandomIntArraySwap(random_list, i);
	}
	for (int i = 0; i < 26; ++i)
	{
		{
			Card newCard(static_cast<Card::Suit>(random_list[i] / 13), static_cast<Card::Rank>(random_list[i] % 13));
			player1_deck_.AddCard(newCard);
		}
		{
			Card newCard(static_cast<Card::Suit>(random_list[i+26] / 13), static_cast<Card::Rank>(random_list[i+26] % 13));
			player2_deck_.AddCard(newCard);
		}
	}
}

void War::RandomIntArraySwap(int * int_list, int position)
{
	int random_position = rand() % 52;
	int temp = int_list[position];
	int_list[position] = int_list[random_position];
	int_list[random_position] = temp;

	return;
}

