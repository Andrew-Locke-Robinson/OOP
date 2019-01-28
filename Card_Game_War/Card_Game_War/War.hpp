#pragma once

#include "Deck.hpp"

class War
{
public:
	War();
	~War();

	int PlayWar();

	void InitializePlayerDecks();
	void RandomIntArraySwap(int* int_list, int position);

private:
	Deck player1_deck_;
	Deck player2_deck_;
};

