#include "player.h"

Player::Player() {}
Player::~Player() {}

void Player::addCard(const Card& c) {
    hand.push_back(c);
}

int Player::handValue() const {
    int sum = 0;
    for (const Card& c : hand) {
        sum += c.getValue();
    }
    return sum;
}
