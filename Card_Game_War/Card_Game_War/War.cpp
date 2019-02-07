#include "War.hpp"
#include <random>
#include <iostream>
#include <vector>



War::War()
{
}


War::~War()
{
}

int War::PlayWar()
{
	// Shuffles a 52 card deck and splits it in half for two players
	InitializePlayerDecks();

	do {
		// if the players have the same top card, put the first two cards into the pot
		if (player1_.deck_.front().Get_Rank() == player2_.deck_.front().Get_Rank())
		{
			for (int i = 0; i < 2; ++i)
			{
				AddCardToPot();
				if (GameOver())
				{
					return WhoWon();
				}
			}
		}
		else if (player1_.deck_.front().Get_Rank() > player2_.deck_.front().Get_Rank())
		{
			AddCardToPot();
			int size_of_pot = pot_.size();
			for (int i = 0; i < size_of_pot; ++i)
			{
				player1_.AddCard(pot_.back());
				pot_.pop_back();
			}
			if (GameOver())
			{
				return WhoWon();
			}
		}
		else {
			AddCardToPot();
			int size_of_pot = pot_.size();
			for (int i = 0; i < size_of_pot; ++i)
			{
				player2_.AddCard(pot_.back());
				pot_.pop_back();
			}
			if (GameOver())
			{
				return WhoWon();
			}
		}
	} while (true);
	
}

void War::InitializePlayerDecks()
{
	while (!player1_.deck_.empty())
	{
		player1_.deck_.pop_front();
	}
	while (!player2_.deck_.empty())
	{
		player2_.deck_.pop_front();
	}

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
			player1_.AddCard(newCard);
		}
		{
			Card newCard(static_cast<Card::Suit>(random_list[i+26] / 13), static_cast<Card::Rank>(random_list[i+26] % 13));
			player2_.AddCard(newCard);
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

bool War::GameOver()
{
	// if either player has an empty deck, the game is over
	if (player1_.deck_.empty() || player2_.deck_.empty())
	{
		if (player1_.deck_.empty())
		{
			std::cout << "Player 2 wins" << std::endl;
		}
		else {
			std::cout << "Player 1 wins" << std::endl;
		}
		return true;
	}
	return false;
}

void War::AddCardToPot()
{
	if (rand() % 2 == 0)
	{
		pot_.push_back(player1_.deck_.front());
		pot_.push_back(player2_.deck_.front());
	}else{
		pot_.push_back(player2_.deck_.front());
		pot_.push_back(player1_.deck_.front());
	}
	player1_.deck_.pop_front();
	player2_.deck_.pop_front();
}

int War::WhoWon()
{
	if (player2_.deck_.empty())
	{
		return 1;
	}
	return 2;
}

