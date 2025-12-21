#ifndef SHIP_H
#define SHIP_H

#include <cstring>   // strncpy

class Ship {
public:
    char name[8];   // ship name
    int  size;      // length
    int  hits;      // hits so far
    bool sunk;      // true if dead
    int  row;       // start row
    int  col;       // start col
    char dir;       // 'H' or 'V'

    Ship();                     // default ctor
    Ship(const char nm[], int sz);  // ctor with name + size
};

#endif
