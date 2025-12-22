#ifndef HMN_H
#define HMN_H

#include "Plyr.h"

/*
 * Human player class.
 * Implements turn logic using user input.
 */
class Hmn : public Plyr {
public:
    Hmn();                  // default ctor
    Hmn(const char nm[]);   // ctor with player name

    // override of base class turn function
    void turn(Plyr &def) override;
};

#endif
