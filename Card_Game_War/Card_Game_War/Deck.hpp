#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <deque>

class Deck
{
public:
	Deck();
	~Deck();

	void AddCard(Card &card);

private:
	std::deque<Card> deck_;
};
#endif  // !DECK_HPP