#include "plfunc.h"
#include "brd.h"

#include <iostream>
#include <cctype>

using namespace std;

int dice() {
    return rand() % 6 + 1;   // 1-6
}

void mkFlt(Ship *flt, int snum) {
    flt[0] = Ship("Car", 5);
    flt[1] = Ship("Bship", 4);
    flt[2] = Ship("Cruz", 3);
    flt[3] = Ship("Sub", 3);
    flt[4] = Ship("Dest", 2);

    for (int i = 0; i < snum; i++) {
        flt[i].hits = 0;
        flt[i].sunk = false;
        flt[i].row  = 0;
        flt[i].col  = 0;
        flt[i].dir  = 'H';
    }
}

bool getPos(const string &in, int &row, int &col) {
    if (in.size() < 2) return false;

    char rCh = toupper(in[0]);
    if (rCh < 'A' || rCh > 'A' + ROWS - 1) return false;

    string cStr = in.substr(1);
    int cNum = 0;

    for (int i = 0; i < static_cast<int>(cStr.size()); i++) {
        if (!isdigit(static_cast<unsigned char>(cStr[i]))) return false;
        cNum = cNum * 10 + (cStr[i] - '0');
    }

    if (cNum < 1 || cNum > COLS) return false;

    row = rCh - 'A';
    col = cNum - 1;

    return true;
}

bool canPut(Plyr &p, Ship &s, int row, int col, char dir) {
    if (dir == 'H') {
        if (col + s.size > COLS) return false;
        for (int c = col; c < col + s.size; c++) {
            if (p.fb[row][c] != '.') return false;
        }
    } else if (dir == 'V') {
        if (row + s.size > ROWS) return false;
        for (int r = row; r < row + s.size; r++) {
            if (p.fb[r][col] != '.') return false;
        }
    } else {
        return false;
    }
    return true;
}

void putShip(Plyr &p, Ship &s) {
    int row = s.row;
    int col = s.col;

    if (s.dir == 'H') {
        for (int c = col; c < col + s.size; c++) {
            p.fb[row][c] = 'S';
        }
    } else {
        for (int r = row; r < row + s.size; r++) {
            p.fb[r][col] = 'S';
        }
    }
}

void setFltMan(Plyr &p) {
    for (int i = 0; i < p.snum; i++) {
        Ship &s = p.flt[i];

        bool ok = false;
        while (!ok) {
            string ttl = string(p.name) + " FLEET";
            prtBrd(p.fb, ROWS, COLS, ttl);

            cout << "Set ship: " << s.name
                 << " (size " << s.size << ")" << endl;
            cout << "Pos (ex: A1, B10): ";
            string pos;
            cin >> pos;

            int row, col;
            if (!getPos(pos, row, col)) {
                cout << "Bad pos. Try agn." << endl << endl;
                continue;
            }

            cout << "Dir H/V: ";
            char dir;
            cin >> dir;
            dir = toupper(dir);

            if (!canPut(p, s, row, col, dir)) {
                cout << "Cant put ship there." << endl << endl;
                continue;
            }

            s.row = row;
            s.col = col;
            s.dir = dir;
            putShip(p, s);
            ok = true;
        }
    }

    string ttl = string(p.name) + " FLEET DONE";
    prtBrd(p.fb, ROWS, COLS, ttl);
}

int hitShip(Plyr &def, int row, int col) {
    for (int i = 0; i < def.snum; i++) {
        Ship &s = def.flt[i];
        int r = s.row;
        int c = s.col;

        if (s.dir == 'H') {
            for (int k = 0; k < s.size; k++) {
                if (r == row && (c + k) == col) {
                    return i;
                }
            }
        } else { // 'V'
            for (int k = 0; k < s.size; k++) {
                if ((r + k) == row && c == col) {
                    return i;
                }
            }
        }
    }
    return -1;
}

bool allSunk(Plyr &p) {
    for (int i = 0; i < p.snum; i++) {
        if (!p.flt[i].sunk) return false;
    }
    return true;
}

void pickFr(Plyr &p1, Plyr &p2, Plyr *&cur, Plyr *&oth) {
    const int MINN = 1;
    const int MAXN = 100;

    while (true) {
        int g1, g2;

        cout << endl << "Pick who starts! (" << MINN << "-" << MAXN << ")" << endl;

        cout << p1.name << " pick: ";
        cin >> g1;
        while (g1 < MINN || g1 > MAXN) {
            cout << "Pick " << MINN << "-" << MAXN << ": ";
            cin >> g1;
        }

        cout << p2.name << " pick: ";
        cin >> g2;
        while (g2 < MINN || g2 > MAXN) {
            cout << "Pick " << MINN << "-" << MAXN << ": ";
            cin >> g2;
        }

        int tgt = rand() % (MAXN - MINN + 1) + MINN;
        cout << "Num is: " << tgt << endl;

        int d1 = g1 - tgt;
        if (d1 < 0) d1 = -d1;
        int d2 = g2 - tgt;
        if (d2 < 0) d2 = -d2;

        if (d1 < d2) {
            cout << p1.name << " closer. Goes first!" << endl;
            cout << p2.name << " terrible guess. Pathetic really. Im almost insulted >:)" << endl;
            cur = &p1;
            oth = &p2;
            break;
        } else if (d2 < d1) {
            cout << p2.name << " closer. Goes first!" << endl;
            cout << p1.name << " that was an awful guess. You deserve to lose :)" << endl;
            cur = &p2;
            oth = &p1;
            break;
        } else {
            cout << "Tie. You both suck. Try again :)" << endl;
        }
    }
}
