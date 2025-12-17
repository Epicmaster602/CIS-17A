#include <iostream>

using namespace std;

// Converts Fahrenheit to Celsius
double cels(double fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}

int main()
{
    int f;

    cout << "Fahrenheit  Celsius" << endl;

    for (f = 0; f <= 20; f++)
    {
        cout << f << "           " << cels(f) << endl;
    }

    return 0;
}
