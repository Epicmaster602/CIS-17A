/* 
 * Author: Tyler Purba
 * Date: 2025-09-11
 * Purpose: Function that multiplies a number by 10
 */

#include <iostream>
using namespace std;

int timesTen(int number);   // function prototype

int main() {
    int input;
    cout << "Type a number: ";
    cin >> input;
    cout << timesTen(input);
    return 0;
}

int timesTen(int number) {  // function definition
    return number * 10;
}
