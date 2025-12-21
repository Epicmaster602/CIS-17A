#ifndef GAME_H
#define GAME_H

#include "Plyr.h"
#include "cfg.h"
#include "Stat.h"

class Game {
private:
    Plyr *p1;
    Plyr *p2;

public:
    Game(Plyr *a, Plyr *b);

    void run(Stat st[], int &sn, int max);
};

#endif
