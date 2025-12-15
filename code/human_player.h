#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H
#include "player.h"
#include <string>

class HumanPlayer : public Player {
private:
    std::string name;
public:
    HumanPlayer(const std::string& playerName);
    void makeMove() override;
    std::string getName() const;
};
#endif
