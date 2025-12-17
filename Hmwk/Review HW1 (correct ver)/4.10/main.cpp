#include <iostream>

using namespace std;

int main()
{
    int mon;
    int year;
    int days;

    cout << "Enter a month (1-12): ";
    cin >> mon;

    cout << "Enter a year: ";
    cin >> year;

    // Check for leap year
    bool leap = false;

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            leap = true;
    }
    else
    {
        if (year % 4 == 0)
            leap = true;
    }

    // Determine days in month
    if (mon == 1 || mon == 3 || mon == 5 || mon == 7 ||
        mon == 8 || mon == 10 || mon == 12)
    {
        days = 31;
    }
    else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
    {
        days = 30;
    }
    else if (mon == 2)
    {
        if (leap)
            days = 29;
        else
            days = 28;
    }

    cout << days << " days" << endl;

    return 0;
}
