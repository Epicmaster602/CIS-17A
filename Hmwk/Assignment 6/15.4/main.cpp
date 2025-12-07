#include <iostream>
using namespace std;

class Time {
protected:
    int hr;
    int mn;
    int sc;

public:
    Time() { hr = 0; mn = 0; sc = 0; }
    Time(int h, int m, int s) {
        hr = h; mn = m; sc = s;
    }

    int getHr() { return hr; }
    int getMn() { return mn; }
    int getSc() { return sc; }
};

class MilTime : public Time {
private:
    int milHr;     // 0000 - 2359
    int milSc;     // 0 - 59

public:
    MilTime() : Time() {
        milHr = 0;
        milSc = 0;
    }

    MilTime(int mh, int ms) {
        setTime(mh, ms);
    }

    void setTime(int mh, int ms) {
        // input check
        if (mh < 0 || mh > 2359) {
            cout << "Bad mil hour.\n";
            return;
        }
        if (ms < 0 || ms > 59) {
            cout << "Bad secs.\n";
            return;
        }

        milHr = mh;
        milSc = ms;

        // convert
        hr = milHr / 100;
        mn = milHr % 100;
        sc = milSc;

        if (hr > 12) hr -= 12;
        if (hr == 0) hr = 12;
    }

    int getHour() { return milHr; }      // military hour
    int getStandHr() { return hr; }      // normal hour
};

int main() {
    int mh, ms;

    cout << "Enter mil hour (0000-2359): ";
    cin >> mh;

    cout << "Enter secs (0-59): ";
    cin >> ms;

    MilTime t(mh, ms);

    cout << "\nMil format: " << t.getHour() << ":" << ms << endl;
    cout << "Std format: " 
         << t.getStandHr() << ":"
         << t.getMn() << ":"
         << t.getSc() << endl;

    return 0;
}
