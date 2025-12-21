#ifndef PLYR_H
#define PLYR_H

#include "cfg.h"
#include "Ship.h"

class Plyr {
public:
    char name[16];   
    
protected:
    char **fb;       // fleet board
    char **sb;       // shot board
    Ship *flt;       // ships
    int  snum;       // ship count

public:
    Plyr();
    Plyr(const char nm[]);
    virtual ~Plyr();

    virtual void turn(Plyr &def) = 0;
};


#endif
