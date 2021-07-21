#pragma once
#include <algorithm>
#include "GenericPlayer.h"

using namespace std;

class Deck :
    public Hand
{
public:
    Deck();
    virtual ~Deck();

    void Populate();
    void Shuffle();

    void Deal(Hand& aHand);
    void AdditionalCards(GenericPlayer& aGenericPlayer);

};

