#ifndef STFUNC_H
#define STFUNC_H

#include "Stat.h"

extern const char SFIL[];

int  rdStat(Stat st[], int max);
void wrStat(Stat st[], int sn);
int  findSt(Stat st[], int sn, const char nm[]);
void updSt(Stat st[], int &sn, int max, const char nm[], bool win);
void shwSt(Stat st[], int sn);

#endif
