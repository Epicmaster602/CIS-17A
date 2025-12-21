#include "Plyr.h"
#include "brd.h"
#include <cstring>

using namespace std;

// mkFlt is implemented elsewhere (currently still in main, later we move it)
void mkFlt(Ship *flt, int snum);

Plyr::Plyr() {
    name[0] = '\0';
    fb  = nullptr;
    sb  = nullptr;
    flt = nullptr;
    snum = SNUM;
}

Plyr::Plyr(const char nm[]) {
    strncpy(name, nm, 15);
    name[15] = '\0';

    snum = SNUM;

    fb = mkBrd(ROWS, COLS);
    sb = mkBrd(ROWS, COLS);

    clrBrd(fb, ROWS, COLS, '.');
    clrBrd(sb, ROWS, COLS, '.');

    flt = new Ship[snum];
    mkFlt(flt, snum);
}

Plyr::~Plyr() {
    if (fb != nullptr) { delBrd(fb, ROWS); fb = nullptr; }
    if (sb != nullptr) { delBrd(sb, ROWS); sb = nullptr; }
    if (flt != nullptr) { delete [] flt; flt = nullptr; }
}
