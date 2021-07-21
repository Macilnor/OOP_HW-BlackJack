#include "Deck.h"

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck()
{
}

void Deck::Populate()
{
    Clear();
    for (int s = (int)Card::Suit::CLUBS; s <= (int)Card::Suit::SPADES; ++s)
    {
        for (int r = (int)Card::Rank::ACE; r <= (int)Card::Rank::KING; ++r)
        {
            Add(new Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
        }
    }
}

void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
    if (!m_Cards.empty())
    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }

}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;

    while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;

        if (aGenericPlayer.IsBusted())
        {
            aGenericPlayer.Bust();
        }
    }

}
