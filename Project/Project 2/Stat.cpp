#include "Stat.h"
using namespace std;

int Stat::cnt = 0;

Stat::Stat() {
    nm[0] = '\0';
    pl = 0;
    wn = 0;
    cnt++;

}

Stat::Stat(const Stat &o) {
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
    pl++;
}

void Stat::addWn() {
    wn++;
}

int Stat::getPl() const {
    return pl;
}

int Stat::getWn() const {
    return wn;
}

void Stat::rdBin(std::ifstream &fin) {
    fin.read(nm, 16);
    fin.read(reinterpret_cast<char*>(&pl), sizeof(pl));
    fin.read(reinterpret_cast<char*>(&wn), sizeof(wn));
    nm[15] = '\0';
}

void Stat::wrBin(std::ofstream &fout) const {
    fout.write(nm, 16);
    fout.write(reinterpret_cast<const char*>(&pl), sizeof(pl));
    fout.write(reinterpret_cast<const char*>(&wn), sizeof(wn));
}

std::ostream &operator<<(std::ostream &out, const Stat &s) {
    out << std::left << std::setw(16) << s.getNm()
        << std::setw(8)  << s.getPl()
        << std::setw(8)  << s.getWn();
    return out;
}

// If you’re using these two operators, keep them.
// They don’t change the game output unless you call them.
bool operator<(const Stat &a, const Stat &b) {
    return a.getWn() < b.getWn();
}

bool operator==(const Stat &a, const Stat &b) {
    return std::strcmp(a.getNm(), b.getNm()) == 0;
}
