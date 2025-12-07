#include <iostream>
#include <string>
using namespace std;

struct Drink {
    string name;
    int cost; // in cents
    int qty;
};

int main(){
    Drink d[5] = {
        {"Cola",       75, 20},
        {"Root Beer",  75, 20},
        {"Lemon-Lime", 75, 20},
        {"Grape Soda", 80, 20},
        {"Cream Soda", 80, 20}
    };

    int total = 0; // total earned in cents

    while (true) {
        // print menu with numbers + explicit Quit=0
        for (int i = 0; i < 5; i++) {
            cout << (i+1) << ":" << d[i].name << " " << d[i].cost << " " << d[i].qty <<endl;
        }
        cout << "0:Quit"<<endl;

        int choice;
        if (!(cin >> choice)) break;        // EOF -> quit
        if (choice == 0) break;
        if (choice < 1 || choice > 5) {     // invalid menu choice
            cout << "Invalid"<<endl;
            continue;
        }

        Drink &x = d[choice - 1];
        if (x.qty <= 0) {                   // sold out message required
            cout << "Sold Out"<<endl;
            continue;
        }

        int money;                          // cents inserted
        if (!(cin >> money)) break;

        // input validation per spec: 0..100
        if (money < 0 || money > 100) {
            cout << "Invalid"<<endl;
            continue;
        }
        if (money < x.cost) {
            cout << "Not enough"<<endl;
            continue;
        }

        // vend
        x.qty -= 1;
        total += x.cost;
        int change = money - x.cost;

        // print ONLY change
        cout << change <<endl;
    }

    // print ONLY total earned at end (in cents)
    cout << total <<endl;
    return 0;
}
