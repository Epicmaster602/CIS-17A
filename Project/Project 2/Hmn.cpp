#include "Hmn.h"
#include "brd.h"
#include "cfg.h"
#include <iostream>
#include <string>

using namespace std;

// helpers implemented in plfunc.cpp
bool getPos(const string &in, int &row, int &col);
int  hitShip(Plyr &def, int row, int col);

// human player turn: prompt user and process shot
void Hmn::turn(Plyr &def) {
    string ttl1 = string(name) + " FLEET";
    string ttl2 = string(name) + " SHOTS";

    // show current boards
    prtBrd(fb, ROWS, COLS, ttl1);
    prtBrd(sb, ROWS, COLS, ttl2);

    int row, col;
    string pos;

    // get valid target position
    while (true) {
        cout << name << " tgt (ex: A1): ";
        cin >> pos;

        if (!getPos(pos, row, col)) {
            cout << "Bad pos. Try agn." << endl;
            continue;
        }
        if (sb[row][col] != '.') {
            cout << "Used pos. Pick new." << endl;
            continue;
        }
        break;
    }

    // process hit or miss
    if (def.getFb()[row][col] == 'S') {
        cout << "Hit!" << endl;
        def.getFb()[row][col] = 'X';
        sb[row][col] = 'X';

        int idx = hitShip(def, row, col);
        if (idx != -1) {
            Ship &s = def.getFlt()[idx];
            s.hits++;
            if (s.hits >= s.size && !s.sunk) {
                s.sunk = true;
                cout << "You sunk " << s.name << "!" << endl;
            }
        }
    } else if (def.getFb()[row][col] == '.') {
        cout << "Miss." << endl;
        def.getFb()[row][col] = 'O';
        sb[row][col] = 'O';
    } else {
        cout << "Weird pos, already hit." << endl;
    }

    cout << endl;
}

// constructors just forward to base class
Hmn::Hmn() : Plyr() {}
Hmn::Hmn(const char nm[]) : Plyr(nm) {}
