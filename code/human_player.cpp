#include "human_player.h"
#include <iostream>

HumanPlayer::HumanPlayer(const std::string& playerName)
    : Player(), name(playerName) {}

void HumanPlayer::makeMove() {
    std::cout << name << ", jouw beurt!" << std::endl;
}

std::string HumanPlayer::getName() const {
    return name;
}
