#include "Ship.h"

Ship::Ship() {
    name[0] = '\0';
    size = 0;
    hits = 0;
    sunk = false;
    row = 0;
    col = 0;
    dir = 'H';
}

Ship::Ship(const char nm[], int sz) {
    strncpy(name, nm, 7);
    name[7] = '\0';

    size = sz;
    hits = 0;
    sunk = false;
    row = 0;
    col = 0;
    dir = 'H';
}
