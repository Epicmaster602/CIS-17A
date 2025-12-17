#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DayOfYear
{
private:
    int day;

    static string mons[12];
    static int days[12];

    int getMon(string mon)
    {
        for (int i = 0; i < 12; i++)
        {
            if (mons[i] == mon)
                return i;
        }
        return -1;
    }

public:
    // Day-of-year constructor
    DayOfYear(int num)
    {
        day = num;
    }

    // Month + day-of-month constructor
    DayOfYear(string mon, int dmo)
    {
        int idx = getMon(mon);

        if (idx == -1)
        {
            cout << "Error: Invalid month.\n";
            exit(1);
        }

        if (dmo < 1 || dmo > days[idx])
        {
            cout << "Error: Invalid day for that month.\n";
            exit(1);
        }

        int sum = 0;
        for (int i = 0; i < idx; i++)
            sum += days[i];

        day = sum + dmo;
    }

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

    // Prefix ++
    DayOfYear operator++()
    {
        if (day == 365)
            day = 1;
        else
            day++;

        return *this;
    }

    // Postfix ++
    DayOfYear operator++(int)
    {
        DayOfYear temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix --
    DayOfYear operator--()
    {
        if (day == 1)
            day = 365;
        else
            day--;

        return *this;
    }

    // Postfix --
    DayOfYear operator--(int)
    {
        DayOfYear temp = *this;
        --(*this);
        return temp;
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
    string mon;
    int dmo;

    cout << "Enter month (I recommend April :D): ";
    cin >> mon;

    cout << "Enter day of month: ";
    cin >> dmo;

    DayOfYear d(mon, dmo);

    cout << "\nStart: ";
    d.print();
    cout << endl;

    cout << "Prefix ++: ";
    ++d;
    d.print();
    cout << endl;

    cout << "Postfix ++: ";
    d++;
    d.print();
    cout << endl;

    cout << "Prefix --: ";
    --d;
    d.print();
    cout << endl;

    cout << "Postfix --: ";
    d--;
    d.print();
    cout << endl;

    // Wrap test (end of year -> start)
    DayOfYear endd("December", 31);
    cout << "\nWrap test: ";
    endd.print();
    cout << " -> ";
    ++endd;
    endd.print();
    cout << endl;

    // Wrap test (start of year -> end)
    DayOfYear sttd("January", 1);
    cout << "Wrap test: ";
    sttd.print();
    cout << " -> ";
    --sttd;
    sttd.print();
    cout << endl;

    return 0;
}
