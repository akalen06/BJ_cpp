#ifndef CPU_PLAYER_H
#define CPU_PLAYER_H
#include "player.h"
#include <string>

class CPUPlayer : public Player {
private:
    std::string name;
    int hitThreshold;  // CPU hits tot deze waarde (standaard 17)
public:
    CPUPlayer(const std::string& playerName, int threshold = 17);
    void makeMove() override;
    std::string getName() const;
};
#endif
