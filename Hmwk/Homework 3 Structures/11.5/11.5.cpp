#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Weather {
    string month;
    double rain;     // inches
    int high;        // F
    int low;         // F
    double avg;      // F (computed)
};

int main() {
    const int N = 12;
    string names[N] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };

    Weather w[N];

    double totalRain = 0.0;
    double sumAvgs = 0.0;

    // initialize months
    for (int i = 0; i < N; i++) {
        w[i].month = names[i];

        cout << w[i].month << " total rainfall (inches): ";
        while (!(cin >> w[i].rain)) { // crude clear
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a number: ";
        }

        // high temp with validation
        cout << w[i].month << " high temp (F): ";
        while (!(cin >> w[i].high) || w[i].high < -100 || w[i].high > 140) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Out of range (-100..140). Try again: ";
        }

        // low temp with validation
        cout << w[i].month << " low temp (F): ";
        while (!(cin >> w[i].low) || w[i].low < -100 || w[i].low > 140) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Out of range (-100..140). Try again: ";
        }

        // if someone enters low > high, just swap (keeps it simple)
        if (w[i].low > w[i].high) {
            int t = w[i].low;
            w[i].low = w[i].high;
            w[i].high = t;
        }

        w[i].avg = (w[i].high + w[i].low) / 2.0;
        totalRain += w[i].rain;
        sumAvgs += w[i].avg;
    }

    // stats: highest "high", lowest "low"
    int idxHigh = 0, idxLow = 0;
    for (int i = 1; i < N; i++) {
        if (w[i].high > w[idxHigh].high) idxHigh = i;
        if (w[i].low  < w[idxLow].low ) idxLow  = i;
    }

    double avgMonthlyRain = totalRain / N;
    double avgOfMonthlyAvgs = sumAvgs / N;

    cout << fixed << setprecision(2);
    cout <<endl<<"Year Summary"<<endl;
    cout << "Total rainfall: " << totalRain << " in"<<endl;
    cout << "Average monthly rainfall: " << avgMonthlyRain << " in"<<endl;

    cout << "Highest temperature: " << w[idxHigh].high << " F (" << w[idxHigh].month << ")"<<endl;
    cout << "Lowest temperature: "  << w[idxLow].low  << " F (" << w[idxLow].month  << ")"<<endl;

    cout << "Average of monthly average temps: " << avgOfMonthlyAvgs << " F"<<endl;

    return 0;
}
