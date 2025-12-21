#ifndef HMN_H
#define HMN_H

#include "Plyr.h"

class Hmn : public Plyr {
public:
    Hmn();
    Hmn(const char nm[]);

    void turn(Plyr &def) override;
};

#endif
