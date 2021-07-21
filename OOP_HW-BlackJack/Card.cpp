#include "Card.h"

Card::Card(Suit suite, Rank rank, bool flipUp) : m_Suit(suite), m_Rank(rank), m_faceUp(flipUp)
{
}

void Card::Flip()
{
	m_faceUp = !m_faceUp;
}

int Card::getValue() const
{
    int value = 0;
    if (m_faceUp)
    {

        value = static_cast<int>(m_Rank);

        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "\005", "\004", "\003", "\006" };
    
    if (aCard.m_faceUp)
    {
        os << RANKS[static_cast<int>(aCard.m_Rank)] << SUITS[static_cast<int>(aCard.m_Suit)];
    }
    else
    {
        os << "XX";
    }
    
    return os;
}
