/* 
 * File:   main.cpp
 * Author: Tyler Purba
 * 
 * Proj:   Battleship Game
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <stdexcept>

#include "Ship.h"
#include "Stat.h"
#include "Plyr.h"
#include "brd.h"
#include "stfunc.h"
#include "plfunc.h"
#include "cfg.h"
#include "Hmn.h"
#include "Hm2.h"
#include "Game.h"

using namespace std;

// template example (prints any array type that supports <<)
template <class T>
void prtArr(T arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << endl;
    }
}

const int MS = 20;   // max stats records

int main(int argc, char** argv) {
    // seed randomness for start picker (and any other random parts)
    srand(static_cast<unsigned int>(time(0)));

    Stat st[MS];
    int sn = 0;

    // exception example: stats file may not exist on first run
    try {
        sn = rdStat(st, MS);
    }
    catch (const exception &e) {
        sn = 0;
        cout << "No stat file yet. New file will be made." << endl;
    }

    int opt = 0;
    while (true) {
        cout << "    BATTLESHIP    " << endl;
        cout << "1) New game" << endl;
        cout << "2) View stats" << endl;
        cout << "3) Quit" << endl;
        cout << "Opt: ";
        cin >> opt;

        if (cin.fail()) {
        cin.clear();      // clear fail flag
        cin.ignore(10000, '\n');  // drop bad input
        cout << "Bad opt." << endl;
        continue;         // restart menu loop
        }

        if (opt == 1) {
            char nm1[16], nm2[16];

            cout << "Name P1: ";
            cin >> setw(16) >> nm1;

            cout << "Name P2: ";
            cin >> setw(16) >> nm2;

            // player objects (derived from Plyr)
            Hmn p1(nm1);
            Hm2 p2(nm2);

            // aggregation: Game "has" two players
            Game g(&p1, &p2);
            g.run(st, sn, MS);
        }
        else if (opt == 2) {
            shwSt(st, sn);
        }
        else if (opt == 3) {
            break;
        }
        else {
            cout << "Bad opt." << endl;
        }
    }

    return 0;
}
