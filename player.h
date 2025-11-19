#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "card.h"

class Player {
protected:
    std::vector<Card> hand;
public:
    Player();
    virtual ~Player();
    void addCard(const Card& c);
    int handValue() const;
    virtual void makeMove() = 0; // Abstract: afgeleiden MOETEN dit implementeren
};

#endif
