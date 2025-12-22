#include "Ship.h"

// default constructor: empty ship (values set later)
Ship::Ship() {
    name[0] = '\0';
    size = 0;
    hits = 0;
    sunk = false;
    row = 0;
    col = 0;
    dir = 'H';
}

// constructor with name and size
Ship::Ship(const char nm[], int sz) {
    // copy name safely into fixed-size array
    strncpy(name, nm, 7);
    name[7] = '\0';

    size = sz;
    hits = 0;
    sunk = false;
    row = 0;
    col = 0;
    dir = 'H';
}
