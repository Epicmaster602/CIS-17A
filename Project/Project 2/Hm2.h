#ifndef HM2_H
#define HM2_H

#include "Plyr.h"

class Hm2 : public Plyr {
public:
    Hm2();
    Hm2(const char nm[]);

    void turn(Plyr &def) override;
};

#endif
