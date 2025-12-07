#include <iostream>
using namespace std;

// Absolute Value Template

template <class T>
T absoluteVal(T x) {
    return (x < 0 ? -x : x);
}

// Driver Program

int main() {
    int i = -10;
    double d = -3.75;
    long l = -999999;
    float f = -5.2f;

    cout << "abs(int): " << absoluteVal(i) << endl;
    cout << "abs(double): " << absoluteVal(d) << endl;
    cout << "abs(long): " << absoluteVal(l) << endl;
    cout << "abs(float): " << absoluteVal(f) << endl;

    return 0;
}
