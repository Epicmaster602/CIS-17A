#include <iostream>
#include <string>

using namespace std;

class DayOfYear
{
private:
    int day;

    static string mons[12];
    static int days[12];

public:
    // Stores day of year
    DayOfYear(int d)
    {
        day = d;
    }

    // Prints month and day
    void print()
    {
        int num = day;
        int mon = 0;

        while (num > days[mon])
        {
            num -= days[mon];
            mon++;
        }

        cout << mons[mon] << " " << num;
    }
};

// Static member definitions
string DayOfYear::mons[12] =
{
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

int DayOfYear::days[12] =
{
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

int main()
{
    int num;

    cout << "Enter day of year (1 - 365): ";
    cin >> num;

    if (num < 1 || num > 365)
        return 0;

    DayOfYear d(num);
    d.print();

    cout << endl;
    return 0;
}
