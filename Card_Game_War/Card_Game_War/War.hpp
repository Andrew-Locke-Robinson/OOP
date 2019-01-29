#pragma once

#include <vector>
#include "Deck.hpp"

class War
{
public:
	War();
	~War();

	int PlayWar();

	void InitializePlayerDecks();
	void RandomIntArraySwap(int* int_list, int position);
	bool GameOver();
	void AddCardToPot();

private:
	Deck player1_;
	Deck player2_;
	std::vector<Card> pot_;
};

