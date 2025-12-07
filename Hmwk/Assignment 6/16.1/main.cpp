#include <iostream>
#include <string>
using namespace std;

//Exception Classes
class InvalidDay {};
class InvalidMonth {};

//Dateclass
class Date {
private:
    int mon;
    int day;
    int yr;

    string monName(int m) {
        string arr[12] = { "January","February","March","April","May","June",
                           "July","August","September","October","November","December" };
        return arr[m-1];
    }

public:
    Date() {
        mon = 1;
        day = 1;
        yr = 2000;
    }

    Date(int m, int d, int y) {
        if (m < 1 || m > 12)
            throw InvalidMonth();
        if (d < 1 || d > 31)
            throw InvalidDay();

        mon = m;
        day = d;
        yr = y;
    }

    void print1() {
        cout << mon << "/" << day << "/" << yr << endl;
    }

    void print2() {
        cout << monName(mon) << " " << day << ", " << yr << endl;
    }

    void print3() {
        cout << day << " " << monName(mon) << " " << yr << endl;
    }
};

// Driver Program
int main() {
    int m, d, y;

    cout << "Enter month (1-12): ";
    cin >> m;

    cout << "Enter day (1-31): ";
    cin >> d;

    cout << "Enter year: ";
    cin >> y;

    try {
        Date dt(m, d, y);

        cout << "\nFormat 1: ";
        dt.print1();

        cout << "Format 2: ";
        dt.print2();

        cout << "Format 3: ";
        dt.print3();
    }
    catch (InvalidMonth) {
        cout << "\nError: Invalid month entered.\n";
    }
    catch (InvalidDay) {
        cout << "\nError: Invalid day entered.\n";
    }

    return 0;
}
