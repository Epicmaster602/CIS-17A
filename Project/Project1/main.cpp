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
#include <cctype>   // toupper
#include <cstring>  // strcpy

using namespace std;

// Board size
const int ROWS = 14;   // A-N
const int COLS = 14;   // 1-14
const int SNUM = 5;    // number of ships


// -----------------
// Structs
// -----------------

struct Ship {
    char name[8];   // ship name
    int  size;      // length
    int  hits;      // hits so far
    bool sunk;      // true if dead
    int  row;       // start row
    int  col;       // start col
    char dir;       // 'H' or 'V'
};

struct Plyr {
    char name[16];  // player name
    char **fb;      // fleet board
    char **sb;      // shot board
    Ship *flt;      // ships
    int  snum;      // ship count
};

struct Stat {
    char name[16];  // player name
    int  play;      // games played
    int  win;       // games won
};

struct Cpu {
    bool tgt;       // in target mode
    int  hr;        // last hit row
    int  hc;        // last hit col
    int  qnum;      // queue size
    int  qr[20];    // row queue
    int  qc[20];    // col queue
};

int  dice();
int  hitShip(Plyr &def, int row, int col);
bool allSunk(Plyr &p);
void doShot(Plyr &atk, Plyr &def);


const int MS = 20;          // max stats rec
const char SFIL[] = "bstats.dat";  // stats file name

// stats funcs
int  rdStat(Stat st[], int max);
void wrStat(Stat st[], int sn);
int  findSt(Stat st[], int sn, const char nm[]);
void updSt(Stat st[], int &sn, const char nm[], bool win);
void shwSt(Stat st[], int sn);

// who starts
void pickFr(Plyr &p1, Plyr &p2, Plyr *&cur, Plyr *&oth);

// -----------------
// Board functions
// -----------------
char **mkBrd(int row, int col);
void   delBrd(char **brd, int row);
void   clrBrd(char **brd, int row, int col, char ch);
void   prtBrd(char **brd, int row, int col, const string &ttl);

int dice() {
    return rand() % 6 + 1;   // 1-6
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
    return -1;   // not on any ship (should only happen if cell not 'S')
}

bool allSunk(Plyr &p) {
    for (int i = 0; i < p.snum; i++) {
        if (!p.flt[i].sunk) return false;
    }
    return true;
}


void mkFlt(Ship *flt, int snum) {
    strcpy(flt[0].name, "Car");
    flt[0].size = 5;

    strcpy(flt[1].name, "Bship");
    flt[1].size = 4;

    strcpy(flt[2].name, "Cruz");
    flt[2].size = 3;

    strcpy(flt[3].name, "Sub");
    flt[3].size = 3;

    strcpy(flt[4].name, "Dest");
    flt[4].size = 2;

    for (int i = 0; i < snum; i++) {
        flt[i].hits = 0;
        flt[i].sunk = false;
        flt[i].row  = 0;
        flt[i].col  = 0;
        flt[i].dir  = 'H';
    }
}

void setPly(Plyr &p, const char nm[]) {
    strncpy(p.name, nm, 15);
    p.name[15] = '\0';

    p.snum = SNUM;

    p.fb = mkBrd(ROWS, COLS);
    p.sb = mkBrd(ROWS, COLS);

    clrBrd(p.fb, ROWS, COLS, '.');
    clrBrd(p.sb, ROWS, COLS, '.');

    p.flt = new Ship[p.snum];
    mkFlt(p.flt, p.snum);
}

void delPly(Plyr &p) {
    if (p.fb != nullptr) {
        delBrd(p.fb, ROWS);
        p.fb = nullptr;
    }
    if (p.sb != nullptr) {
        delBrd(p.sb, ROWS);
        p.sb = nullptr;
    }
    if (p.flt != nullptr) {
        delete [] p.flt;
        p.flt = nullptr;
    }
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

// player + fleet setup
void setPly(Plyr &p, const char nm[]);
void delPly(Plyr &p);
void mkFlt(Ship *flt, int snum);

// ship place helpers
bool getPos(const string &in, int &row, int &col);
bool canPut(Plyr &p, Ship &s, int row, int col, char dir);
void putShip(Plyr &p, Ship &s);

// manual fleet (strategy panel)
void setFltMan(Plyr &p);

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

bool getPos(const string &in, int &row, int &col) {
    if (in.size() < 2) return false;

    char rCh = toupper(in[0]);
    if (rCh < 'A' || rCh > 'A' + ROWS - 1) return false;

    string cStr = in.substr(1);
    int cNum = 0;

    for (int i = 0; i < static_cast<int>(cStr.size()); i++) {
        if (!isdigit(cStr[i])) return false;
        cNum = cNum * 10 + (cStr[i] - '0');
    }

    if (cNum < 1 || cNum > COLS) return false;

    row = rCh - 'A';
    col = cNum - 1;

    return true;
}

int rdStat(Stat st[], int max) {
    ifstream fin(SFIL, ios::binary);
    if (!fin) return 0;

    int n = 0;
    while (n < max && fin.read(reinterpret_cast<char*>(&st[n]), sizeof(Stat))) {
        n++;
    }
    fin.close();
    return n;
}

void wrStat(Stat st[], int sn) {
    ofstream fout(SFIL, ios::binary);
    if (!fout) return;
    for (int i = 0; i < sn; i++) {
        fout.write(reinterpret_cast<char*>(&st[i]), sizeof(Stat)); // binary file//
    }
    fout.close();
}

int findSt(Stat st[], int sn, const char nm[]) {
    for (int i = 0; i < sn; i++) {
        if (strcmp(st[i].name, nm) == 0) {
            return i;
        }
    }
    return -1;
}

void updSt(Stat st[], int &sn, const char nm[], bool win) {
    int idx = findSt(st, sn, nm);

    if (idx == -1) {
        if (sn >= MS) return;
        idx = sn;
        sn++;

        strncpy(st[idx].name, nm, 15);
        st[idx].name[15] = '\0';
        st[idx].play = 0;
        st[idx].win  = 0;
    }

    st[idx].play++;
    if (win) st[idx].win++;
}

void shwSt(Stat st[], int sn) {
    cout << endl << "--- STATS ---" << endl;
    if (sn == 0) {
        cout << "No stat yet." << endl << endl;
        return;
    }

    cout << left << setw(16) << "Name"
         << setw(8) << "Play"
         << setw(8) << "Win" << endl;

    for (int i = 0; i < sn; i++) {
        cout << left << setw(16) << st[i].name
             << setw(8) << st[i].play
             << setw(8) << st[i].win << endl;
    }
    cout << endl;
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

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    Stat st[MS];
    int  sn = rdStat(st, MS);

    int opt = 0;
    while (true) {
        cout << "    BATTLESHIP    " << endl;
        cout << "1) New game" << endl;
        cout << "2) View stats" << endl;
        cout << "3) Quit" << endl;
        cout << "Opt: ";
        cin >> opt;

        if (opt == 1) {
            Plyr p1, p2;
            p1.fb  = p1.sb  = nullptr;
            p1.flt = nullptr;
            p2.fb  = p2.sb  = nullptr;
            p2.flt = nullptr;

            char nm1[16], nm2[16];

            cout << "Name P1: ";
            cin >> setw(16) >> nm1;

            cout << "Name P2: ";
            cin >> setw(16) >> nm2;

            setPly(p1, nm1);
            setPly(p2, nm2);

            cout << endl << "Place ships for " << p1.name << ":" << endl;
            setFltMan(p1);

            cout << endl << "Place ships for " << p2.name << ":" << endl;
            setFltMan(p2);

            Plyr *cur = &p1;
            Plyr *oth = &p2;
            pickFr(p1, p2, cur, oth);

            while (true) {
                cout << endl << "Turn: " << cur->name << endl;
                doShot(*cur, *oth);

                if (allSunk(*oth)) {
                    cout << endl << cur->name << " wins!" << endl;

                    updSt(st, sn, cur->name, true);
                    updSt(st, sn, oth->name, false);
                    wrStat(st, sn);

                    break;
                }

                Plyr *tmp = cur;
                cur = oth;
                oth = tmp;
            }

            delPly(p1);
            delPly(p2);
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


// make dynamic 2D board row x col
char **mkBrd(int row, int col) {
    char **brd = new char*[row];
    for (int r = 0; r < row; r++) {
        brd[r] = new char[col];
    }
    return brd;
}

// delete dynamic 2D board
void delBrd(char **brd, int row) {
    for (int r = 0; r < row; r++) {
        delete [] brd[r];
    }
    delete [] brd;
}

// fill board with one char (ex: '.')
void clrBrd(char **brd, int row, int col, char ch) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            brd[r][c] = ch;
        }
    }
}

// print board with title + labels
void prtBrd(char **brd, int row, int col, const string &ttl) {
    cout << "--- " << ttl << " ---" << endl;

    cout << "    ";
    for (int c = 0; c < col; c++) {
        if (c + 1 < 10) {
            cout << " " << c + 1 << " ";
        } else {
            cout << c + 1 << " ";
        }
    }
    cout << endl;

    for (int r = 0; r < row; r++) {
        char rLab = 'A' + r;
        cout << " " << rLab << "  ";
        for (int c = 0; c < col; c++) {
            cout << " " << brd[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void doShot(Plyr &atk, Plyr &def) {
    string ttl1 = string(atk.name) + " FLEET";
    string ttl2 = string(atk.name) + " SHOTS";

    prtBrd(atk.fb, ROWS, COLS, ttl1);
    prtBrd(atk.sb, ROWS, COLS, ttl2);

    int row, col;
    string pos;

    while (true) {
        cout << atk.name << " tgt (ex: A1): ";
        cin >> pos;

        if (!getPos(pos, row, col)) {
            cout << "Bad pos. Try agn." << endl;
            continue;
        }
        if (atk.sb[row][col] != '.') {
            cout << "Used pos. Pick new." << endl;
            continue;
        }
        break;
    }

    if (def.fb[row][col] == 'S') {
        cout << "Hit!" << endl;
        def.fb[row][col] = 'X';
        atk.sb[row][col] = 'X';

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
        atk.sb[row][col] = 'O';
    } else {
        cout << "Weird pos, already hit." << endl;
    }

    cout << endl;
}

