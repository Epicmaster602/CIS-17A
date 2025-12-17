#include <iostream>

using namespace std;

int main()
{
    int start;
    int days;
    int i;

    double rate;
    double pop;

    cout << "Enter starting population: ";
    cin >> start;

    while (start < 2)
    {
        cout << "Starting population must be at least 2: ";
        cin >> start;
    }

    cout << "Enter daily increase (%): ";
    cin >> rate;

    while (rate < 0)
    {
        cout << "Daily increase cannot be negative: ";
        cin >> rate;
    }

    cout << "Enter number of days: ";
    cin >> days;

    while (days < 1)
    {
        cout << "Number of days must be at least 1: ";
        cin >> days;
    }

    pop = start;
    rate = rate / 100.0;

    for (i = 1; i <= days; i++)
    {
        cout << "Day " << i << ": " << pop << endl;
        pop = pop + (pop * rate);
    }

    return 0;
}
