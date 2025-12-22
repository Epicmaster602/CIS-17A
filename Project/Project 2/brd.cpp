#include "brd.h"
#include <iostream>

using namespace std;

// allocate a dynamic 2D board (row pointers + column arrays)
char **mkBrd(int row, int col) {
    char **brd = new char*[row];
    for (int r = 0; r < row; r++) {
        brd[r] = new char[col];
    }
    return brd;
}

// free memory allocated by mkBrd
void delBrd(char **brd, int row) {
    for (int r = 0; r < row; r++) {
        delete [] brd[r];
    }
    delete [] brd;
}

// fill entire board with a single character
void clrBrd(char **brd, int row, int col, char ch) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            brd[r][c] = ch;
        }
    }
}

// print board with row/column labels
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
