#ifndef BRD_H
#define BRD_H

#include <string>

/*
 * Board helper functions.
 * Used for creating, clearing, and displaying the game boards.
 */

// allocate a dynamic 2D board (row x col)
char **mkBrd(int row, int col);

// free a dynamic 2D board
void delBrd(char **brd, int row);

// fill board with a single character (ex: '.')
void clrBrd(char **brd, int row, int col, char ch);

// print board with title and row/column labels
void prtBrd(char **brd, int row, int col, const std::string &ttl);

#endif
