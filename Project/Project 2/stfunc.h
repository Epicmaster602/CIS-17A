#ifndef STFUNC_H
#define STFUNC_H

/* Stats helper functions for Battleship.
 *
 * Handles reading/writing the binary stats file and printing stats.
 * Uses the Stat class (name, games played, games won).
 */
#include "Stat.h"

// stats file name (defined in stfunc.cpp)
extern const char SFIL[];

/**
 * @brief Read stats from the binary file into an array.
 * @param st   Array of Stat objects to fill.
 * @param max  Max number of records allowed in st.
 * @return Number of records read.
 */
int  rdStat(Stat st[], int max);

//Write stats array back to the binary file.
void wrStat(Stat st[], int sn);

//Find a stats record by name.
int  findSt(Stat st[], int sn, const char nm[]);

//Update (or create) a player's stats record.
void updSt(Stat st[], int &sn, int max, const char nm[], bool win);


/**
 * @brief Print stats to the console.
 * @param st  Array of Stat objects.
 * @param sn  Number of valid records.
 */
void shwSt(Stat st[], int sn);

#endif
