#include "card.h"

Card::Card(int v, char s) : value(v), suit(s) {}

int Card::getValue() const {return value; }

char Card::getSuit() const {return suit; }
