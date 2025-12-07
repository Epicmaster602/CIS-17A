#include <iostream>
using namespace std;

//Exception Classes 
class BadHour {};
class BadSeconds {};


// Base Class: Time 
class Time {
protected:
    int hr;
    int mn;
    int sc;

public:
    Time() {
        hr = 0;
        mn = 0;
        sc = 0;
    }

    Time(int h, int m, int s) {
        hr = h;
        mn = m;
        sc = s;
    }

    int getHr() { return hr; }
    int getMn() { return mn; }
    int getSc() { return sc; }
};


// Derived Class: MilTime 
class MilTime : public Time {
private:
    int milHr;   // 0000–2359
    int milSc;   // 0–59

public:
    MilTime() : Time() {
        milHr = 0;
        milSc = 0;
    }

    MilTime(int mh, int ms) {
        setTime(mh, ms);
    }

    void setTime(int mh, int ms) {
        if (mh < 0 || mh > 2359)
            throw BadHour();

        if (ms < 0 || ms > 59)
            throw BadSeconds();

        milHr = mh;
        milSc = ms;

        // convert military -> standard
        hr = milHr / 100;
        mn = milHr % 100;
        sc = milSc;

        if (hr > 12) hr -= 12;
        if (hr == 0) hr = 12;
    }

    int getHour() { return milHr; }     // military
    int getStandHr() { return hr; }     // standard hr
};


//  Driver Program 
int main() {
    int mh, ms;

    cout << "Enter mil hour (0000-2359): ";
    cin >> mh;

    cout << "Enter seconds (0-59): ";
    cin >> ms;

    try {
        MilTime t(mh, ms);

        cout << "\nMil format: "
             << t.getHour() << ":" << ms << endl;

        cout << "Std format: "
             << t.getStandHr() << ":"
             << t.getMn() << ":"
             << t.getSc() << endl;
    }
    catch (BadHour) {
        cout << "\nError: Invalid hour entered.\n";
    }
    catch (BadSeconds) {
        cout << "\nError: Invalid seconds entered.\n";
    }

    return 0;
}
