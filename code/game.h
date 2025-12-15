#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "human_player.h"
#include "cpu_player.h"
#include <vector>
#include <memory>

class Game {
private:
    Deck deck;
    std::vector<Player*> players;  // Alle spelers (human + cpu)
    Dealer dealer;

    void dealInitialCards();
    void playerTurn(Player* player, bool isCPU = false);
    void dealerTurn();
    void determineWinners();

public:
    Game();
    ~Game();
    void addHumanPlayer(const std::string& name);
    void addCPUPlayer(const std::string& name, int threshold = 17);
    void play();
    void clearPlayers();
};
#endif
