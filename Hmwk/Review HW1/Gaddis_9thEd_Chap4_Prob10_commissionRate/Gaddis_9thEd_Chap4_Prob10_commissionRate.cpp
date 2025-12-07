
/* 
 * Author: Tyler Purba
 * Date: 2025-09-11
 * Purpose: Display commission rate and bonus based on sales
 */





#include <iostream>
using namespace std;

int main()
{
    double commissionRate;
    double bonus;
    int sales;
    sales = 50000;
    if (sales >= 50000){
        commissionRate = .25;
        bonus = 250;
    }
    cout <<sales << endl;
    cout << commissionRate << endl;
    cout << bonus << endl;
    return 0;
}