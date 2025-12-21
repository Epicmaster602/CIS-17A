#ifndef STAT_H
#define STAT_H

#include <fstream>
#include <iomanip>
#include <cstring>
#include <ostream>

class Stat {
private:
    char nm[16];  // name
    int  pl;      // games played
    int  wn;      // games won
    static int cnt;   // static count (for checkoff)

public:
    Stat();
    Stat(const Stat &o);   // copy ctor
    static int getCnt();   // shows static works

    void setNm(const char n[]);
    const char *getNm() const;

    void addPl();
    void addWn();

    int getPl() const;
    int getWn() const;

    void rdBin(std::ifstream &fin);
    void wrBin(std::ofstream &fout) const;

    // friend for operator<< (checks "friends" later too)
    friend std::ostream &operator<<(std::ostream &out, const Stat &s);
};

// operator overloads (declare here, define in Stat.cpp)
std::ostream &operator<<(std::ostream &out, const Stat &s);

// If you already added these, keep them. If not, you can add them now.
bool operator<(const Stat &a, const Stat &b);
bool operator==(const Stat &a, const Stat &b);

#endif
