#ifndef PLFUNC_H
#define PLFUNC_H

#include <string>
#include "cfg.h"
#include "Ship.h"
#include "Plyr.h"

/*
 * Player-related helper functions.
 * Handles turn logic, ship placement, and win conditions.
 */

// roll a die 
int  dice();

// check which ship was hit (returns index or -1)
int  hitShip(Plyr &def, int row, int col);

// return true if all ships are sunk
bool allSunk(Plyr &p);

// initialize fleet array with ship types
void mkFlt(Ship *flt, int snum);

// ship placement helpers
bool canPut(Plyr &p, Ship &s, int row, int col, char dir);
void putShip(Plyr &p, Ship &s);

// manual fleet setup (player input)
void setFltMan(Plyr &p);

// convert input like "A10" into row/column indexes
bool getPos(const std::string &in, int &row, int &col);

// decide which player goes first
void pickFr(Plyr &p1, Plyr &p2, Plyr *&cur, Plyr *&oth);

#endif
