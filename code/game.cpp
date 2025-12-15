#include "game.h"
#include <iostream>

Game::Game() : deck(), dealer() {}

Game::~Game() {
    clearPlayers();
}

void Game::addHumanPlayer(const std::string& name) {
    players.push_back(new HumanPlayer(name));
}

void Game::addCPUPlayer(const std::string& name, int threshold) {
    players.push_back(new CPUPlayer(name, threshold));
}

void Game::clearPlayers() {
    for (Player* p : players) {
        delete p;
    }
    players.clear();
}

void Game::dealInitialCards() {
    // Iedereen krijgt 2 kaarten
    for (int i = 0; i < 2; ++i) {
        for (Player* p : players) {
            p->addCard(deck.dealCard());
        }
        dealer.addCard(deck.dealCard());
    }

    std::cout << "\n=== INITIAL DEAL ===\n";
    std::cout << "Dealer shows: ";
    dealer.showFirstCard();
    std::cout << "\n\n";
}

void Game::playerTurn(Player* player, bool isCPU) {
    HumanPlayer* human = dynamic_cast<HumanPlayer*>(player);
    CPUPlayer* cpu = dynamic_cast<CPUPlayer*>(player);

    std::string playerName = human ? human->getName() : cpu->getName();

    std::cout << "--- " << playerName << "'s turn ---\n";

    bool playerDone = false;
    while (!playerDone) {
        player->showHandWithValue(playerName);

        int total = player->handValue();
        if (total >= 21) {
            if (total > 21) {
                std::cout << playerName << " busted!\n\n";
            } else {
                std::cout << playerName << " has 21!\n\n";
            }
            playerDone = true;
            continue;
        }

        char choice;
        if (isCPU) {
            // CPU logica: hit tot 17
            CPUPlayer* cpuPlayer = static_cast<CPUPlayer*>(player);
            if (total < 17) {
                choice = 'h';
                std::cout << playerName << " hits.\n";
            } else {
                choice = 's';
                std::cout << playerName << " stands.\n";
            }
        } else {
            // Human input
            std::cout << "Hit or stand? (h/s): ";
            std::cin >> choice;
        }

        if (choice == 'h' || choice == 'H') {
            player->addCard(deck.dealCard());
        } else {
            playerDone = true;
        }
    }
}

void Game::dealerTurn() {
    std::cout << "--- Dealer's turn ---\n";
    dealer.showHandWithValue("Dealer");

    while (dealer.handValue() < 17) {
        std::cout << "Dealer hits.\n";
        dealer.addCard(deck.dealCard());
        dealer.showHandWithValue("Dealer");
    }

    if (dealer.handValue() > 21) {
        std::cout << "Dealer busted!\n";
    } else {
        std::cout << "Dealer stands.\n";
    }
    std::cout << "\n";
}

void Game::determineWinners() {
    std::cout << "=== FINAL RESULTS ===\n";
    int dealerTotal = dealer.handValue();

    for (Player* p : players) {
        HumanPlayer* human = dynamic_cast<HumanPlayer*>(p);
        CPUPlayer* cpu = dynamic_cast<CPUPlayer*>(p);
        std::string playerName = human ? human->getName() : cpu->getName();

        int playerTotal = p->handValue();
        p->showHandWithValue(playerName);

        if (playerTotal > 21) {
            std::cout << playerName << " loses (busted).\n";
        } else if (dealerTotal > 21) {
            std::cout << playerName << " wins (dealer busted)!\n";
        } else if (playerTotal > dealerTotal) {
            std::cout << playerName << " wins!\n";
        } else if (playerTotal < dealerTotal) {
            std::cout << playerName << " loses.\n";
        } else {
            std::cout << playerName << " pushes.\n";
        }
        std::cout << "\n";
    }
}

void Game::play() {
    // Clear alle handen
    for (Player* p : players) {
        p->clearHand();
    }
    dealer.clearHand();

    // Deal initial cards
    dealInitialCards();

    // Elke speler speelt
    for (Player* p : players) {
        CPUPlayer* cpu = dynamic_cast<CPUPlayer*>(p);
        playerTurn(p, cpu != nullptr);
    }

    // Dealer speelt (alleen als minstens 1 speler niet busted)
    bool anyoneStillIn = false;
    for (Player* p : players) {
        if (p->handValue() <= 21) {
            anyoneStillIn = true;
            break;
        }
    }

    if (anyoneStillIn) {
        dealerTurn();
    }

    // Bepaal winnaars
    determineWinners();
}
