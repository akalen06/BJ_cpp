#include "game.h"
#include <iostream>

Game::Game() : deck(), player(), dealer() {}

void Game::play() {
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    bool playerDone = false;
    while(!playerDone) {
        player.showHand();
        std::cout << "Will you hit or stand? (h/s); ";
        char choice;
        std::cin >> choice;

        if (choice == 'h') {
            player.addCard(deck.dealCard());
            if (player.handValue() > 21) {
                std::cout << "You've busted\n";
                playerDone = true;
            }
        }   else {
            playerDone = true;
        }
    }
    if (player.handValue() <= 21){
        while (dealer.handValue() < 17){
            dealer.addCard(deck.dealCard());
        }
    }
    std::cout << "Player: " << player.handValue() << "\n";
    std::cout << "Dealer: " << dealer.handValue() << "\n";

    if (player.handValue() > 21) {
        std::cout << "Dealer wins.\n";
    } else if (dealer.handValue() > 21 || player.handValue() > dealer.handValue()) {
        std::cout << "Player wins.\n";
    } else if (player.handValue() < dealer.handValue()) {
        std::cout << "Dealer wins.\n";
    } else {
        std::cout << "Push.\n";
    }

}
