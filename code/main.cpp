#include "game.h"
#include <iostream>

int main() {
    Game game;

    // Setup spelers
    std::cout << "=== BLACKJACK GAME SETUP ===\n";
    std::cout << "How many human players? ";
    int numHumans;
    std::cin >> numHumans;

    for (int i = 0; i < numHumans; ++i) {
        std::cout << "Name for player " << (i+1) << ": ";
        std::string name;
        std::cin >> name;
        game.addHumanPlayer(name);
    }

    std::cout << "How many CPU players? ";
    int numCPUs;
    std::cin >> numCPUs;

    for (int i = 0; i < numCPUs; ++i) {
        std::string cpuName = "CPU" + std::to_string(i+1);
        game.addCPUPlayer(cpuName);
    }

    // Speel de game
    char again = 'y';
    while (again == 'y' || again == 'Y') {
        game.play();
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;
    }

    return 0;
}
