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
    for (int s = static_cast<int>(Card::Suit::CLUBS); s <= static_cast<int>(Card::Suit::SPADES); ++s)
    {
        for (int r = static_cast<int>(Card::Rank::ACE); r <= static_cast<int>(Card::Rank::KING); ++r)
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
    if (m_Cards.empty())
    {
        cout << "Out of cards. Unable to deal. Taking new deck." << endl;
        Populate();
        Shuffle();
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
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
