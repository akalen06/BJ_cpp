#ifndef CARD_H
#define CARD_H

class Card {
private:
    int value;          //1-11
    char suit;          // h = harten, s = schoppen, d = diamonds, c = clubs
public:
    Card(int v, char s);
    int getValue() const;
    char getSuit()  const;
};

#endif // CARD_H
