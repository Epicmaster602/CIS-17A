#include "Game.h"
#include "plfunc.h"
#include "stfunc.h"
#include <iostream>

using namespace std;

Game::Game(Plyr *a, Plyr *b) {
    p1 = a;
    p2 = b;
}

void Game::run(Stat st[], int &sn, int max) {
    cout << endl << "Place ships for " << p1->name << ":" << endl;
    setFltMan(*p1);

    cout << endl << "Place ships for " << p2->name << ":" << endl;
    setFltMan(*p2);

    Plyr *cur = p1;
    Plyr *oth = p2;
    pickFr(*p1, *p2, cur, oth);

    while (true) {
        cout << endl << "Turn: " << cur->name << endl;
        cur->turn(*oth);

        if (allSunk(*oth)) {
            cout << endl << cur->name << " wins!" << endl;

            updSt(st, sn, max, cur->name, true);
            updSt(st, sn, max, oth->name, false);

            wrStat(st, sn);
            break;
        }

        Plyr *tmp = cur;
        cur = oth;
        oth = tmp;
    }
}
