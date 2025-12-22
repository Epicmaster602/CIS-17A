#include "Game.h"
#include "plfunc.h"
#include "stfunc.h"
#include <iostream>

using namespace std;

Game::Game(Plyr *a, Plyr *b) {
    // store player pointers (players owned outside Game)
    p1 = a;
    p2 = b;
}

void Game::run(Stat st[], int &sn, int max) {
    // fleet setup
    cout << endl << "Place ships for " << p1->name << ":" << endl;
    setFltMan(*p1);

    cout << endl << "Place ships for " << p2->name << ":" << endl;
    setFltMan(*p2);

    // decide who goes first
    Plyr *cur = p1;
    Plyr *oth = p2;
    pickFr(*p1, *p2, cur, oth);

    // main turn loop
    while (true) {
        cout << endl << "Turn: " << cur->name << endl;
        cur->turn(*oth);   // polymorphism: calls correct derived turn()

        if (allSunk(*oth)) {
            cout << endl << cur->name << " wins!" << endl;

            // update stats and save
            updSt(st, sn, max, cur->name, true);
            updSt(st, sn, max, oth->name, false);

            wrStat(st, sn);
            break;
        }

        // swap players
        Plyr *tmp = cur;
        cur = oth;
        oth = tmp;
    }
}
