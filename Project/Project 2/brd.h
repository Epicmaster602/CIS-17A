#ifndef BRD_H
#define BRD_H

#include <string>

// make dynamic 2D board row x col
char **mkBrd(int row, int col);

// delete dynamic 2D board
void delBrd(char **brd, int row);

// fill board with one char (ex: '.')
void clrBrd(char **brd, int row, int col, char ch);

// print board with title + labels
void prtBrd(char **brd, int row, int col, const std::string &ttl);

#endif
