#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    // Constructor with input validation
    Date(int mon, int dy, int yr)
    {
        if (mon >= 1 && mon <= 12)
            month = mon;
        else
            month = 1;

        if (dy >= 1 && dy <= 31)
            day = dy;
        else
            day = 1;

        year = yr;
    }

    void printNum()
    {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printMon()
    {
        string names[12] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
        };

        cout << names[month - 1] << " " << day << ", " << year << endl;
    }

    void printDay()
    {
        string names[12] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
        };

        cout << day << " " << names[month - 1] << " " << year << endl;
    }
};

int main()
{
    Date today(04, 20, 2007);

    today.printNum();
    today.printMon();
    today.printDay();
    cout <<"Welcome to the world me!" << endl;
    return 0;
}
