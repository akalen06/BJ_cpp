#include "dealer.h"
#include <iostream>

Dealer::Dealer() : Player() {}

void Dealer::makeMove() {
    // Dealer trekt kaarten tot waarde 17 of meer
    std::cout << "Dealer maakt een zet (dummy, implementatie volgt in Game)." << std::endl;
}
