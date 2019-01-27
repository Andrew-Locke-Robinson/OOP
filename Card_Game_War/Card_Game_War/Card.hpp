#pragma once

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

private:
	Suit suit_;
	Rank rank_;
};