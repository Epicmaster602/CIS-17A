#ifndef PLFUNC_H
#define PLFUNC_H

#include <string>
#include "cfg.h"
#include "Ship.h"
#include "Plyr.h"

int  dice();

int  hitShip(Plyr &def, int row, int col);
bool allSunk(Plyr &p);

void mkFlt(Ship *flt, int snum);

bool canPut(Plyr &p, Ship &s, int row, int col, char dir);
void putShip(Plyr &p, Ship &s);

void setFltMan(Plyr &p);
bool getPos(const std::string &in, int &row, int &col);

void pickFr(Plyr &p1, Plyr &p2, Plyr *&cur, Plyr *&oth);

#endif
