#include "deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    // Eenvoudige deck (52 kaarten)
    for (char s : {'h', 's', 'd', 'c'}) {
        for (int v = 1; v <= 11; ++v) {
            cards.emplace_back(v, s);
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::dealCard() {
    Card c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::isEmpty() const {
    return cards.empty();
}
