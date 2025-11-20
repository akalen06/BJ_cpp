#include "game.h"
#include <iostream>

Game::Game() : deck(), player(), dealer() {}

void Game::play() {
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    // Simpel demo van moves (implementatie volgt)
    player.makeMove();
    dealer.makeMove();

    std::cout << "Spel gestart!" << std::endl;
}
