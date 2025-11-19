#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "human_player.h"

class Game {
private:
    Deck deck;
    HumanPlayer player;
    Dealer dealer;
public:
    Game();
    void play();
};

#endif
