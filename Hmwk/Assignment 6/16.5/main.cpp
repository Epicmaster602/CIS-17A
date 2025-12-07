#include <iostream>
using namespace std;

// Total Template
template <class T>
T total(int cnt) {
    T sum = 0;
    T val;

    cout << "Enter " << cnt << " values:\n";

    for (int i = 0; i < cnt; i++) {
        cin >> val;
        sum += val;
    }

    return sum;
}

//Driver Program
int main() {
    int n;

    cout << "How many ints? ";
    cin >> n;
    cout << "Total ints: " << total<int>(n) << "\n\n";

    cout << "How many doubles? ";
    cin >> n;
    cout << "Total doubles: " << total<double>(n) << "\n\n";

    cout << "How many longs? ";
    cin >> n;
    cout << "Total longs: " << total<long>(n) << "\n\n";

    return 0;
}
