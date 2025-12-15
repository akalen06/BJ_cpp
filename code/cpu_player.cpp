#include "cpu_player.h"
#include <iostream>

CPUPlayer::CPUPlayer(const std::string& playerName, int threshold)
    : Player(), name(playerName), hitThreshold(threshold) {}

void CPUPlayer::makeMove() {
    // Wordt aangeroepen vanuit Game::play()
    std::cout << name << " is thinking..." << std::endl;
}

std::string CPUPlayer::getName() const {
    return name;
}
