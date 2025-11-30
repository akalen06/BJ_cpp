#include "player.h"
#include "iostream"

Player::Player() {}
Player::~Player() {}

void Player::addCard(const Card& c) {
    hand.push_back(c);
}
void Player::showHand() const {
    std::cout << "Hand: ";
    for (const Card& c : hand) {        // hand is je std::vector<Card>
        std::cout << c.getValue() << c.getSuit() << " ";
    }
    std::cout << "\n";
}


int Player::handValue() const {
    int sum = 0;
    for (const Card& c : hand) {
        sum += c.getValue();
    }
    return sum;
}
