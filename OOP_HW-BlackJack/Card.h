#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Card
{
public:
	enum class Suit {
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	enum class Rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,	NINE, TEN, JACK, QUEEN, KING
	};

	Card(Suit suite, Rank rank, bool flipUp = true);
	void Flip();
	int getValue() const;

private:
	Suit m_Suit;
	Rank m_Rank;
	bool m_faceUp;
	friend ostream& operator<<(ostream& os, const Card& aCard);
};

