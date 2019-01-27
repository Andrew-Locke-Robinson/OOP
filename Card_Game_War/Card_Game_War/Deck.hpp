#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <vector>

class Deck
{
public:

	void AddCard(Card &card);

private:
	std::vector<Card> deck_;
};
#endif  // !DECK_HPP