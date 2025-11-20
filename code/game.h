#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "human_player.h"

class Game {
private:
    Deck deck;          //composition: Game is composed of a deck
    HumanPlayer player; //composition: game is composed of a humanplayer
    Dealer dealer;      //composition: game is composed of a dealer
public:
    Game();
    void play();
};

#endif
