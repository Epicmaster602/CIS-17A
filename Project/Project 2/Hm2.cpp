#include "Hm2.h"
#include "brd.h"
#include "cfg.h"
#include <iostream>
#include <string>

using namespace std;

bool getPos(const string &in, int &row, int &col);
int  hitShip(Plyr &def, int row, int col);

void Hm2::turn(Plyr &def) {
      string ttl1 = string(name) + " FLEET";
    string ttl2 = string(name) + " SHOTS";

    prtBrd(fb, ROWS, COLS, ttl1);
    prtBrd(sb, ROWS, COLS, ttl2);

    int row, col;
    string pos;

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

    if (def.fb[row][col] == 'S') {
        cout << "Hit!" << endl;
        def.fb[row][col] = 'X';
        sb[row][col] = 'X';

        int idx = hitShip(def, row, col);
        if (idx != -1) {
            Ship &s = def.flt[idx];
            s.hits++;
            if (s.hits >= s.size && !s.sunk) {
                s.sunk = true;
                cout << "You sunk " << s.name << "!" << endl;
            }
        }
    } else if (def.fb[row][col] == '.') {
        cout << "Miss." << endl;
        def.fb[row][col] = 'O';
        sb[row][col] = 'O';
    } else {
        cout << "Weird pos, already hit." << endl;
    }

    cout << endl;
}

Hm2::Hm2() : Plyr() {}
Hm2::Hm2(const char nm[]) : Plyr(nm) {}
