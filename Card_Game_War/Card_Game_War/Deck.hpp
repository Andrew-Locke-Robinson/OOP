#pragma once

#include "Card.hpp"
#include <vector>

class Deck
{
public:

	void AddCard(Card &card) { deck_.push_back(card); }

private:
	std::vector<Card> deck_;
};