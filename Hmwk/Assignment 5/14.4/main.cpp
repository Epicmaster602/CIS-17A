#include <iostream>

using namespace std;

class NumDays
{
private:
    double hours;

public:
    // Constructor
    NumDays(double hrs)
    {
        hours = hrs;
    }

    void setHrs(double hrs)
    {
        hours = hrs;
    }

    double getHrs()
    {
        return hours;
    }

    double getDays()
    {
        return hours / 8.0;
    }

    // Add hours from two objects
    NumDays operator+(NumDays rhs)
    {
        return NumDays(hours + rhs.hours);
    }

    // Subtract hours from two objects
    NumDays operator-(NumDays rhs)
    {
        return NumDays(hours - rhs.hours);
    }

    // Prefix ++
    NumDays operator++()
    {
        hours++;
        return *this;
    }

    // Postfix ++
    NumDays operator++(int)
    {
        NumDays temp = *this;
        hours++;
        return temp;
    }

    // Prefix --
    NumDays operator--()
    {
        hours--;
        return *this;
    }

    // Postfix --
    NumDays operator--(int)
    {
        NumDays temp = *this;
        hours--;
        return temp;
    }
};

int main()
{
    NumDays a(12);
    NumDays b(18);

    NumDays sum = a + b;
    NumDays dif = b - a;

    cout << "a hrs: " << a.getHrs() << endl;
    cout << "a day: " << a.getDays() << endl;

    cout << "b hrs: " << b.getHrs() << endl;
    cout << "b day: " << b.getDays() << endl << endl;

    cout << "sum h: " << sum.getHrs() << endl;
    cout << "sum d: " << sum.getDays() << endl;

    cout << "dif h: " << dif.getHrs() << endl;
    cout << "dif d: " << dif.getDays() << endl << endl;

    cout << "++a: ";
    ++a;
    cout << a.getHrs() << " " << a.getDays() << endl;

    cout << "a++: ";
    a++;
    cout << a.getHrs() << " " << a.getDays() << endl;

    cout << "--b: ";
    --b;
    cout << b.getHrs() << " " << b.getDays() << endl;

    cout << "b--: ";
    b--;
    cout << b.getHrs() << " " << b.getDays() << endl;

    return 0;
}
