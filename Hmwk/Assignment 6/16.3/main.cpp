#include <iostream>
using namespace std;

// Template Functions

template <class T>
T minimum(T a, T b) {
    return (a < b ? a : b);
}

template <class T>
T maximum(T a, T b) {
    return (a > b ? a : b);
}

// Driver Program
int main() {
    // ints
    int i1 = 5, i2 = 9;
    cout << "min(int): " << minimum(i1, i2) << endl;
    cout << "max(int): " << maximum(i1, i2) << endl;

    // doubles
    double d1 = 3.5, d2 = 2.8;
    cout << "min(double): " << minimum(d1, d2) << endl;
    cout << "max(double): " << maximum(d1, d2) << endl;

    // chars
    char c1 = 'k', c2 = 'a';
    cout << "min(char): " << minimum(c1, c2) << endl;
    cout << "max(char): " << maximum(c1, c2) << endl;

    // strings
    string s1 = "apple", s2 = "banana";
    cout << "min(string): " << minimum(s1, s2) << endl;
    cout << "max(string): " << maximum(s1, s2) << endl;

    return 0;
}
