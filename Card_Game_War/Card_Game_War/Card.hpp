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
		data_(static_cast<unsigned>(suit) << 4 | static_cast<unsigned>(rank))
	{
	}

	Rank Get_Rank() { return static_cast<Rank>(data_ & 0xf); }
	Suit Get_Suit() { return static_cast<Suit>(data_ >> 4); }

private:
	unsigned char data_;
};
#endif  // !CARD_HPP