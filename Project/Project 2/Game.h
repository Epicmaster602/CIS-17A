#ifndef GAME_H
#define GAME_H

#include "Plyr.h"
#include "cfg.h"
#include "Stat.h"

/*
 * Game class
 * Controls one full Battleship match between two players.
 * Demonstrates aggregation (Game has two Plyr objects).
 */
class Game {
private:
    Plyr *p1;   // player 1
    Plyr *p2;   // player 2

public:
    Game(Plyr *a, Plyr *b);   // store player pointers

    // run a full game and update stats
    void run(Stat st[], int &sn, int max);
};

#endif
