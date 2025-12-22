#ifndef HM2_H
#define HM2_H

#include "Plyr.h"

/*
 * Human player class. (2!)
 * Implements turn logic using user input.
 */
class Hm2 : public Plyr {
public:
    Hm2();                  // default ctor
    Hm2(const char nm[]);   // ctor with player name

    // override of base class turn function
    void turn(Plyr &def) override;
};

#endif


