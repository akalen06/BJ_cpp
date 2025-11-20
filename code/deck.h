#ifndef DECK_H
#define DECK_H
#include <vector>
#include "card.h"
class Deck {
private:
    std::vector<Card> cards;
public:
    Deck();
    bool isEmpty() const;
    Card dealCard();
};

#endif // DECK_H
