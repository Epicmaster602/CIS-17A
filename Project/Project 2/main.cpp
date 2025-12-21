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
#include <stdexcept>

using namespace std;

template <class T>
void prtArr(T arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << endl;
    }
}

const int MS = 20;          // max stats rec

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    Stat st[MS];
    int sn = 0;

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

        if (opt == 1) {
           char nm1[16], nm2[16];

            cout << "Name P1: ";
            cin >> setw(16) >> nm1;

            cout << "Name P2: ";
            cin >> setw(16) >> nm2;

            // constructor handles everything
            Hmn p1(nm1);
            Hm2 p2(nm2);

        }}
            

    return 0;
}





