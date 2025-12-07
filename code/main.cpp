#include "game.h"
#include <iostream>

int main() {
    Game game;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
    game.play();

    std::cout << "Play again? (y/n): ";
    std::cin >> again;

    }
    return 0;
}
