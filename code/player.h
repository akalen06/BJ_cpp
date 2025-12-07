#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "card.h"

class Player {
protected:
    std::vector<Card> hand; //Encapsulation: hand only modifiable by player via class methods, restricts direct acces to hand from outside the class
public:
    Player();
    virtual ~Player();
    void addCard(const Card& c);
    void showHand() const;
    int handValue() const;       //abstraction: caller doesn't need to know internal hand structure
    void showHandWithValue(const std::string& name) const; //nieuw
    void clearHand();
    virtual void makeMove() = 0; //Polymorphism: enables dynamic dispatch for all player types
                                 //Base Class: defines inerface for all types of players
                                // abstract base class: enforces interface, cannot instantiate player
                                //virtual function: enables sublcasses to provide custom implementations
};

#endif
