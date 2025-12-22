#include "Plyr.h"
#include "brd.h"
#include <cstring>

using namespace std;

// helper to initialize fleet array
void mkFlt(Ship *flt, int snum);

Plyr::Plyr() {
    name[0] = '\0';
    fb  = nullptr;
    sb  = nullptr;
    flt = nullptr;
    snum = SNUM;
}

Plyr::Plyr(const char nm[]) {
    // copy player name
    strncpy(name, nm, 15);
    name[15] = '\0';

    snum = SNUM;

    // allocate boards dynamically
    fb = mkBrd(ROWS, COLS);
    sb = mkBrd(ROWS, COLS);

    // initialize boards to empty
    clrBrd(fb, ROWS, COLS, '.');
    clrBrd(sb, ROWS, COLS, '.');

    // allocate and initialize fleet
    flt = new Ship[snum];
    mkFlt(flt, snum);
}

Plyr::~Plyr() {
    // clean up all dynamically allocated memory
    if (fb != nullptr) { delBrd(fb, ROWS); fb = nullptr; }
    if (sb != nullptr) { delBrd(sb, ROWS); sb = nullptr; }
    if (flt != nullptr) { delete [] flt; flt = nullptr; }
}
