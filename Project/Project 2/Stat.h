#ifndef STAT_H
#define STAT_H

#include <fstream>
#include <iomanip>
#include <cstring>
#include <ostream>

/*
 * Stat class
 * Stores win/loss information for a single player.
 * Used for reading/writing stats to a binary file.
 */
class Stat {
private:
    char nm[16];  // player name (fixed size for binary I/O)
    int  pl;      // games played
    int  wn;      // games won
    static int cnt;   // static count (for checkoff)

public:
    Stat();                 // default ctor
    Stat(const Stat &o);    // copy ctor
    static int getCnt();    // return number of Stat objects created

    void setNm(const char n[]);
    const char *getNm() const;

    void addPl();   // increment games played
    void addWn();   // increment games won

    int getPl() const;
    int getWn() const;

    // binary file helpers
    void rdBin(std::ifstream &fin);
    void wrBin(std::ofstream &fout) const;

    // friend for operator<< (checks "friends" requirement)
    friend std::ostream &operator<<(std::ostream &out, const Stat &s);
};

// operator overloads (defined in Stat.cpp)
std::ostream &operator<<(std::ostream &out, const Stat &s);

// comparison operators (used for sorting / comparisons if needed)
bool operator<(const Stat &a, const Stat &b);
bool operator==(const Stat &a, const Stat &b);

#endif
