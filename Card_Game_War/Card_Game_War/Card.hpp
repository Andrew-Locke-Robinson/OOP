#ifndef CARD_HPP
#define CARD_HPP

class Card
{
public:
	enum Suit {
		spade,club,diamond,heart
	};

	enum Rank {
		two,three,four,five,six,seven,eight,nine,ten,jack,queen,king,ace
	};

	Card(Suit suit, Rank rank):
		suit_(suit), rank_(rank)
	{}

	Suit suit_;
	Rank rank_;
};
#endif  // !CARD_HPP