#include "Stat.h"
using namespace std;

// static member initialization
int Stat::cnt = 0;

Stat::Stat() {
    nm[0] = '\0';
    pl = 0;
    wn = 0;
    cnt++;  // track number of Stat objects created
}

Stat::Stat(const Stat &o) {
    // copy all data from source object
    strncpy(nm, o.nm, 15);
    nm[15] = '\0';
    pl = o.pl;
    wn = o.wn;
    cnt++;
}

int Stat::getCnt() {
    return cnt;
}

void Stat::setNm(const char n[]) {
    strncpy(nm, n, 15);
    nm[15] = '\0';
}

const char *Stat::getNm() const {
    return nm;
}

void Stat::addPl() {
    pl++;   // increment games played
}

void Stat::addWn() {
    wn++;   // increment games won
}

int Stat::getPl() const {
    return pl;
}

int Stat::getWn() const {
    return wn;
}

void Stat::rdBin(std::ifstream &fin) {
    // read fixed-size binary record
    fin.read(nm, 16);
    fin.read(reinterpret_cast<char*>(&pl), sizeof(pl));
    fin.read(reinterpret_cast<char*>(&wn), sizeof(wn));
    nm[15] = '\0';
}

void Stat::wrBin(std::ofstream &fout) const {
    // write fixed-size binary record
    fout.write(nm, 16);
    fout.write(reinterpret_cast<const char*>(&pl), sizeof(pl));
    fout.write(reinterpret_cast<const char*>(&wn), sizeof(wn));
}

std::ostream &operator<<(std::ostream &out, const Stat &s) {
    // formatted output for stats display
    out << std::left << std::setw(16) << s.getNm()
        << std::setw(8)  << s.getPl()
        << std::setw(8)  << s.getWn();
    return out;
}

// comparison operators (not required for gameplay)
bool operator<(const Stat &a, const Stat &b) {
    return a.getWn() < b.getWn();
}

bool operator==(const Stat &a, const Stat &b) {
    return std::strcmp(a.getNm(), b.getNm()) == 0;
}
