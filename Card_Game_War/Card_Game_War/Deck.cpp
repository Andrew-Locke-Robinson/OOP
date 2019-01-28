#include "Card.hpp"
#include "Deck.hpp"

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::AddCard(Card &card)
{ 
	deck_.push_back(card); 
}
