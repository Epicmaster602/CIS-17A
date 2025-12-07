#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a 4-digit number using digits 0-7 only: ";
    cin >> num;

    if (num < 0 || num > 7777) {
        cout << "Invalid input: only digits 0-7 allowed." << endl;
        return 0;
    }

    // extract digits (thousands, hundreds, tens, ones)
    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    // check digits
    if (d1 > 7 || d2 > 7 || d3 > 7 || d4 > 7) {
        cout << "Invalid input: digits must be between 0-7 only." << endl;
        return 0;
    }

    // encrypt step: add 3 mod 8
    d1 = (d1 + 3) % 8;
    d2 = (d2 + 3) % 8;
    d3 = (d3 + 3) % 8;
    d4 = (d4 + 3) % 8;

    // swap 1<->3, 2<->4
    int t = d1; d1 = d3; d3 = t;
    t = d2; d2 = d4; d4 = t;

    int encrypted = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
    cout << "Encrypted number: " << encrypted << endl;

    return 0;
}
