#include "stfunc.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>

using namespace std;

// stats binary file
const char SFIL[] = "bstats.dat";

int rdStat(Stat st[], int max) {
    ifstream fin(SFIL, ios::binary);

    // exception example: first run may not have a stats file yet
    if (!fin) {
        throw runtime_error("Stat file not found");
    }

    int n = 0;
    while (n < max) {
        // read name first to check EOF cleanly
        char tmp[16];
        fin.read(tmp, 16);
        if (!fin) break;

        // put cursor back so Stat can read the full record
        fin.seekg(-16, ios::cur);
        st[n].rdBin(fin);
        n++;
    }

    fin.close();
    return n;
}

void wrStat(Stat st[], int sn) {
    ofstream fout(SFIL, ios::binary);
    if (!fout) return;  // can't save

    for (int i = 0; i < sn; i++) {
        st[i].wrBin(fout);
    }
    fout.close();
}

int findSt(Stat st[], int sn, const char nm[]) {
    for (int i = 0; i < sn; i++) {
        if (strcmp(st[i].getNm(), nm) == 0) {
            return i;
        }
    }
    return -1;
}

void updSt(Stat st[], int &sn, int max, const char nm[], bool win) {
    int idx = findSt(st, sn, nm);

    // new player: add record if there is room
    if (idx == -1) {
        if (sn >= max) return;
        idx = sn;
        sn++;

        st[idx].setNm(nm);
    }

    st[idx].addPl();
    if (win) st[idx].addWn();
}

void shwSt(Stat st[], int sn) {
    cout << endl << "--- STATS ---" << endl;
    if (sn == 0) {
        cout << "No stat yet." << endl << endl;
        return;
    }

    cout << left << setw(16) << "Name"
         << setw(8)  << "Play"
         << setw(8)  << "Win" << endl;

    for (int i = 0; i < sn; i++) {
        cout << st[i] << endl;
    }
    cout << endl;
}
