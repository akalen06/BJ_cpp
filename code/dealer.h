#ifndef DEALER_H
#define DEALER_H
#include "player.h"

class Dealer : public Player {
public:
    Dealer();
    void makeMove() override;
    void showFirstCard() const;
};

#endif
