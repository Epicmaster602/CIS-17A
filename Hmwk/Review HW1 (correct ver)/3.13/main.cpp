#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double YEN_PER_DOLLAR = 98.93;
    const double EURO_PER_DOLLAR = 0.74;

    double dollars;
    double yen;
    double euro;

    cout << "Enter dollar amount: ";
    cin >> dollars;

    yen = dollars * YEN_PER_DOLLAR;
    euro = dollars * EURO_PER_DOLLAR;

    cout << fixed << showpoint << setprecision(2);

    cout << "Yen: " << yen << endl;
    cout << "Euros: " << euro << endl;

    return 0;
}
