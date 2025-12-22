#ifndef PLYR_H
#define PLYR_H

#include "cfg.h"
#include "Ship.h"

/*
 * Plyr (Player) base class
 * Shared data and behavior for all player types.
 * Used to demonstrate inheritance and polymorphism.
 */
class Plyr {
public:
    char name[16];   // player name
    
protected:
    // protected so derived classes can access boards and ships
    char **fb;       // fleet board
    char **sb;       // shot board
    Ship *flt;       // fleet of ships
    int  snum;       // number of ships
    // allow helper functions to access protected boards/fleet
    friend bool canPut(Plyr &p, Ship &s, int row, int col, char dir);
    friend void putShip(Plyr &p, Ship &s);
    friend void setFltMan(Plyr &p);

    friend int  hitShip(Plyr &def, int row, int col);
    friend bool allSunk(Plyr &p);

public:
    Plyr();                  // default ctor
    Plyr(const char nm[]);   // ctor with name
    virtual ~Plyr();         // virtual dtor for polymorphic cleanup

    // pure virtual function forces derived classes to implement turn logic
    virtual void turn(Plyr &def) = 0;
    char **getFb() { return fb; }
    char **getSb() { return sb; }
    Ship *getFlt() { return flt; }
    int  getSn() const { return snum; }
};

#endif
