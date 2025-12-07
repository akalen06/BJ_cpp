#include "game.h"
#include <iostream>

Game::Game() : deck(), player(), dealer() {}

void Game::play() {
    player.clearHand();
    dealer.clearHand();

    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    std::cout << "Dealer shows: ";
    dealer.showFirstCard();
    std::cout << "\n";

    bool playerDone = false;
    while (!playerDone) {
        player.showHand();
        std::cout << "Will you hit or stand? (h/s): ";
        char choice;
        std::cin >> choice;

        if (choice == 'h') {
            player.addCard(deck.dealCard());
            int total = player.handValue();
            if (total >= 21) {
                if (total > 21) {
                    std::cout << "You've busted\n";
                } else { // total == 21
                    std::cout << "You have 21!\n";
                }
                playerDone = true;    // stopt direct bij 21 of bust
            }
        }
             else {
            playerDone = true;
        }
    }

    if (player.handValue() <= 21) {
        while (dealer.handValue() < 17) {
            dealer.addCard(deck.dealCard());
        }
    }

    int playerTotal = player.handValue();
    int dealerTotal = dealer.handValue();

    player.showHandWithValue("Player");
    dealer.showHandWithValue("Dealer");

    if (playerTotal > 21) {
        std::cout << "Dealer wins.\n";
    } else if (dealerTotal > 21 || playerTotal > dealerTotal) {
        std::cout << "Player wins.\n";
    } else if (playerTotal < dealerTotal) {
        std::cout << "Dealer wins.\n";
    } else {
        std::cout << "Push.\n";
    }
}
