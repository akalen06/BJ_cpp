#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H
#include "player.h"

class HumanPlayer : public Player { // Inheritance: reuses code and methods from player
public:
    HumanPlayer();
    void makeMove() override; //Abstraction: hides user input details, provides simple interface
                              //Polymorphism: enables dynamic behavior for different player types
                              // virtual function: HUmanPlayer provides specific move behavior
};

#endif
