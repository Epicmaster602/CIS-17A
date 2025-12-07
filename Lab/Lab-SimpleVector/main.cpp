#include <iostream>
#include "SimpleVector.h"
using namespace std;

void printVector(SimpleVector<int> &v, const string &label) {
    cout << label << " (size = " << v.size() << "): ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    SimpleVector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;

    printVector(v, "Initial");

    v.pshBack(40);
    v.pshBack(50);
    printVector(v, "After pshBack(40), pshBack(50)");

    v.pshFrnt(5);
    v.pshFrnt(0);
    printVector(v, "After pshFrnt(5), pshFrnt(0)");

    int back1 = v.popBack();
    int back2 = v.popBack();
    cout << "Popped from back: " << back1 << ", " << back2 << endl;
    printVector(v, "After two popBack");

    int front1 = v.popFrnt();
    int front2 = v.popFrnt();
    cout << "Popped from front: " << front1 << ", " << front2 << endl;
    printVector(v, "After two popFrnt");

    return 0;
}
