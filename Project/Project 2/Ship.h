#ifndef SHIP_H
#define SHIP_H

#include <cstring>   // strncpy

/*
 * Ship class
 * Represents a single ship in the Battleship game.
 * Stores position, orientation, and hit state.
 */
class Ship {
public:
    char name[8];   // ship name (fixed size for simplicity)
    int  size;      // ship length
    int  hits;      // number of hits taken
    bool sunk;      // true when ship is sunk
    int  row;       // starting row on board
    int  col;       // starting column on board
    char dir;       // orientation: 'H' or 'V'

    Ship();                        // default ctor
    Ship(const char nm[], int sz); // ctor with name and size
};

#endif
