#include <iostream>

using namespace std;

int main()
{
    double cels;
    double fahr;

    cout << "Enter Celsius temperature: ";
    cin >> cels;

    fahr = (9.0 / 5.0) * cels + 32;

    cout << "Fahrenheit temperature: " << fahr << endl;

    return 0;
}
